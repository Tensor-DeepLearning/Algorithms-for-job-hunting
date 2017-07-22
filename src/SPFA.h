/************************************************
  FileName    : SPFA.h           ;
  Description :                                 ;
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
#ifndef _SPFA_H_
#define _SPFA_H_
#include "SuperPathFinding.h"
namespace Chirl 
{
    /************************************************************************
     思      路：https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm 
     算法复杂度：
     ************************************************************************/
    class CSPFA : public CSuperPathFinding
    {
    public:
        vector<int> Spfa(vector<set<SEdge> *> adjList, int s, int e)
        {
            if (!(s >= 0 && s < adjList.size() && e >= 0 && e < adjList.size()))
            {
                cerr << "<Warning:>"
                        "\n\t Please input valid start vertex and end vertex!\n";
                return vector<int>();
            }

            vector<int> cost(adjList.size(), INF);
            vector<int> paths(adjList.size(), 0);
            vector<char> status(adjList.size(), 0);     //标记当前点是否在openList中;
            queue<int> openList; 

            openList.push(s);
            cost[s] = 0;
            paths[s] = NONE;

            while (!openList.empty())
            {
                int curIdx = openList.front();
                openList.pop();
                status[curIdx] = 0;
                set<_SEdge> *edgs = adjList[curIdx];

                for (auto itr = edgs->begin(); itr != edgs->end(); ++itr)
                {
                    if (cost[curIdx] + itr->w < cost[itr->e])
                    {
                        cost[itr->e] = cost[curIdx] + itr->w;
                        paths[itr->e] = curIdx;
                        if (status[itr->e] == 0)
                        {
                            openList.push(itr->e);
                            status[itr->e] = 1;
                        }
                    }
                }
            }

            return GetPath(paths, s, e);
        }
        vector<int> DoPathFinding(vector<set<SEdge> *> adjList, int s, int e)
        {
            return Spfa(adjList, s, e);
        }
   
    public:
        static void test()
        {
            CSPFA obj;
            obj.DoTest(&obj);
        }
    };
  
}


#endif //!_SPFA_H_
