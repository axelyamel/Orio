#
# Implementation of the exhaustive search algorithm 
#

import sys, time
import orio.main.tuner.search.search
from orio.main.util.globals import *
from orio.main.tuner.stat_record import recCoords

#-----------------------------------------------------

class Exhaustive(orio.main.tuner.search.search.Search):
    '''The search engine that uses an exhaustive search approach'''

    def __init__(self, params):
        '''
        Instantiate an exhaustive search engine given a dictionary of options.
        @param params: dictionary of options needed to configure the search algorithm.
        '''

        orio.main.tuner.search.search.Search.__init__(self, params)

        # read all algorithm-specific arguments
        self.__readAlgoArgs()

        # complain if the total number of search runs is defined (i.e. exhaustive search
        # only needs to be run once)
        if self.total_runs > 1:
            err('orio.main.tuner.search.exhaustive: the total number of %s search runs must be one (or can be undefined)' %
                   self.__class__.__name__)
            sys.exit(1)
            

    #-----------------------------------------------------
    # Method required by the search interface
    def searchBestCoord(self):
        '''
        Explore the search space and return the coordinate that yields the best performance
        (i.e. minimum performance cost).
        
        @return:  A list of coordinates
        '''

        info('\n----- begin exhaustive search -----')

        # get the total number of coordinates to be tested at the same time
        coord_count = 1
        if self.use_parallel_search:
            coord_count = self.num_procs
        top_perf={}
        
        # record the best coordinate and its best performance cost
        best_coord = None
        top_coords = {}
        best_perf_cost = self.MAXFLOAT
        corr_transfer  = self.MAXFLOAT
        
        # start the timer
        start_time = time.time()

        # start from the origin coordinate (i.e. [0,0,...])
        coord = [0] * self.total_dims 
        coords = [coord]
        while len(coords) < coord_count:
            coord = self.__getNextCoord(coord)
            if coord:
                coords.append(coord)
            else:
                break
        
        recFlag = True
        
        # evaluate every coordinate in the search space
        while True:

            # determine the performance cost of all chosen coordinates
            perf_costs = self.getPerfCosts(coords)
                        
            # compare to the best result
            pcost_items = perf_costs.items()
            pcost_items.sort(lambda x,y: cmp(eval(x[0]),eval(y[0])))
            for coord_str, (perf_cost,transfer_costs) in pcost_items:
                coord_val = eval(coord_str)
                #info('cost: %s' % (perf_cost))
                floatNums = [float(x) for x in perf_cost]
                transferFloats = [float(x) for x in transfer_costs]

                if len(perf_cost) == 1:
                    mean_perf_cost = sum(floatNums)
                else:
                    mean_perf_cost = sum(floatNums[1:]) / (len(perf_cost)-1)
                mean_transfer = sum(transferFloats) / len(transfer_costs)

                info('coordinate: %s, average cost: %s, all costs: %s, average transfer time: %s' % (coord_val, mean_perf_cost, perf_cost, mean_transfer))
                
                if mean_perf_cost < best_perf_cost and perf_cost > 0.0:
                    best_coord = coord_val
                    best_perf_cost = mean_perf_cost
                    corr_transfer  = mean_transfer
                    info('>>>> best coordinate found: %s, average cost: %e, average transfer time: %s' % (coord_val, mean_perf_cost, mean_transfer))
            
            # record time elapsed vs best perf cost found so far in a format that could be read in by matlab/octave
            #progress = 'init' if recFlag else 'continue'
            #recFlag = False
            #IOtime = recCoords(time.time()-start_time, best_perf_cost, progress)
            # don't include time on recording data in the tuning time
            #start_time += IOtime

            # check if the time is up
            if self.time_limit > 0 and (time.time()-start_time) > self.time_limit:
                break

            # get to all the next coordinates in the search space
            coords = []
            while len(coords) < coord_count:
                if coord:
                    coord = self.__getNextCoord(coord)
                if coord:
                    coords.append(coord)
                else:
                    break

            # check if all coordinates have been visited
            if len(coords) == 0:
                break

        # compute the total search time
        search_time = time.time() - start_time

        info('----- end exhaustive search -----')
        
        # record time elapsed vs best perf cost found so far in a format that could be read in by matlab/octave
        #recCoords(time.time()-start_time, best_perf_cost, 'done')
        
        # return the best coordinate
        return best_coord,(best_perf_cost,corr_transfer),search_time,len(coords)
    
    # Private methods       
    #--------------------------------------------------
        
    def __readAlgoArgs(self):
        '''To read all algorithm-specific arguments'''
                
        for vname, rhs in self.search_opts.iteritems():
            err('orio.main.tuner.search.exhaustive: unrecognized %s algorithm-specific argument: "%s"' %
                   (self.__class__.__name__, vname))
            sys.exit(1)

    #--------------------------------------------------

    def __getNextCoord(self, coord):
        '''
        Return the next neighboring coordinate to be considered in the search space.
        Return None if all coordinates in the search space have been visited.
        
        @return: the
        '''
        next_coord = coord[:]
        for i in range(0, self.total_dims):
            ipoint = next_coord[i]
            iuplimit = self.dim_uplimits[i]
            if ipoint < iuplimit-1:
                next_coord[i] += 1
                break
            else:
                next_coord[i] = 0
                if i == self.total_dims - 1:
                    return None
        return next_coord

