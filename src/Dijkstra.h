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

using namespace std;
const int NONE   =   -1;
namespace Chirl
{
    /************************************************************************
     思      路：请参阅Wiki:https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
     算法复杂度：
     ************************************************************************/
    class CDijkstra
    {
    private:
        typedef struct _SEdge
        {
            int s, e, w;

            bool operator<(const _SEdge &rh) const
            {
                if (rh.w == w)
                {
                    return e < rh.e;
                }
                return w < rh.w;
            }
        }SEdge;

        enum {INF = 0xFFFFFFF};

        vector<int> GetPath(vector<int> paths, int s, int e)
        {
            vector<int> path;
            path.reserve(paths.size());

            int curIdx = e;
            while (curIdx != -1)
            {
                path.push_back(curIdx);
                curIdx = paths[curIdx];
            }

             reverse(path.begin(), path.end());
            return path;
        }
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
            
            cost[s] = 0; path[s] = -1;
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
  


    

        static void test()
        {
            /*********测试用例************
             有向图的结构采用邻接矩阵形式表示，矩阵中元素表示权重，-1表示不可达;
             注;                         
                请仅仅复制数字部分到TestExample中;
             格式;
                图的顶点数 寻路起点 寻路终点

                图邻接矩阵

             用例(https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#/media/File:Dijkstra_Animation.gif);
                6   0   4

                0   7   9   -1  -1  14 
                7   0   10  15  -1  -1
                9   10  0   11  -1   2
                -1  15  11   0   6  -1
                -1  -1  -1   6   0   9
                14  -1  2   -1   9   0

            ******************************/

            //读取图以及起点、终点信息，存储为邻接表结构;
            int numVertex, s, e;

            cout << "Please input vertex num、 start vertex and end vertex: \n";
            cin >> numVertex >> s >> e;
            vector<set<SEdge> *> adjList;
            adjList.reserve(numVertex);

            cout << "Please input the adjacent matrix:\n";
            for (int i = 0; i < numVertex; ++i)
            {
                set<SEdge> *edgs = new set<SEdge>;
                SEdge tmp;
                tmp.s = i;
                for (int j = 0; j < numVertex; ++j)
                {
                    cin >> tmp.w;
                    if (tmp.w > 0)
                    {
                        tmp.e = j;
                        edgs->insert(tmp);
                    }
                }
                adjList.push_back(edgs);
            }

            CDijkstra su;
            vector<int> path = su.Dijkstra(adjList, s, e);
            
            //输出最短路径;
            cout << "The shortest path from " << s << " to " << e << " is: " ;
            for (int i = 0; i < path.size()-1; ++i)
            {
                cout << path[i] << " -> ";
            }
            cout << *path.rbegin() << endl;
        }
    };
  
}


#endif //!_Dijkstra_H_
