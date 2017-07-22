/************************************************
  FileName    : Dijkstra.h           ;
  Description : 迪杰斯特拉寻路算法                                ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/16                      ;
              _                                 ;
             /  \         吉                    ;     
            /|oo \         祥                   ;    
           (_|  /_)       物                    ;   
             `@/  \   _    镇                   ;    
             |     \  \\  楼                    ;   
              \||   \  ))  !!                   ;    
              |||\ / \//                        ; 
            _//|| _\  /                         ;
    ______(_/(_|(____/_________                 ;
*************************************************/
#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include "SuperPathFinding.h"
using namespace std;
namespace Chirl
{
    /************************************************************************
     思      路：请参阅Wiki:https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
     算法复杂度：
     ************************************************************************/
    class CDijkstra : public CSuperPathFinding
    {
    public:
        vector<int> Dijkstra(vector<set<SEdge> *> adjList, int s, int e)
        {
            if (!(s >= 0 && s < adjList.size() && e >= 0 && e < adjList.size()))
            {
                cerr << "<Warning:>"
                    "\n\t Please input valid start vertex and end vertex!\n";
                return vector<int>();
            }

            vector<int> cost(adjList.size(), INF);
            vector<int> path(adjList.size(), 0);
            vector<char> openFlag(adjList.size(), 1);
            queue<int> openList; 
            
            cost[s] = 0; path[s] = NONE;
            openList.push(s);
            while (!openList.empty())
            {
                int curVertex = openList.front();
                openList.pop();
                openFlag[curVertex] = 0;

                set<_SEdge> *edges = adjList[curVertex]; 
                for (auto itr = edges->begin(); itr != edges->end(); ++itr)
                {
                    if (openFlag[itr->e])
                    {
                        if (cost[itr->e] == INF)  //push过的点，不再入队;
                        {
                            openList.push(itr->e);
                        }
                        
                        if (cost[curVertex] + itr->w < cost[itr->e]) //是否为更优路径;
                        {
                            path[itr->e] = curVertex;
                            cost[itr->e] = cost[curVertex] + itr->w;
                        }
                    }
                }
            }


            return GetPath(path, s, e);
        }
  
        vector<int> DoPathFinding(vector<set<SEdge> *> adjList, int s, int e)
        {
            return Dijkstra(adjList, s, e);
        }

    public:
        static void test()
        {
            CDijkstra obj;
            obj.DoTest(&obj);
        }
    };
  
}


#endif //!_Dijkstra_H_
