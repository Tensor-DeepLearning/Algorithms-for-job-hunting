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

namespace Chirl
{
    /************************************************************************
     思      路：https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm 
     算法复杂度：
     ************************************************************************/
    class CSPFA
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

        enum {INF = 0xFFFFFFF, NONE = -1};

        vector<int> GetPath(vector<int> paths, int s, int e)
        {
            vector<int> path;
            path.reserve(paths.size());

            int curIdx = e;
            while (curIdx != NONE)
            {
                path.push_back(curIdx);
                curIdx = paths[curIdx];
            }

            reverse(path.begin(), path.end());
            return path;
        }
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

            CSPFA su;
            vector<int> path = su.Spfa(adjList, s, e);
            
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


#endif //!_SPFA_H_
