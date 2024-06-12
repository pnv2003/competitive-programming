#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int id;
    vector<int> tasks_solved;
    int score;
} cont_t;

int main(int argc, char const *argv[])
{
    int nconts, ntasks, pid;
    cin >> nconts >> ntasks >> pid;

    vector<cont_t> vcont(nconts);
    vector<int> v_task_nsolved(ntasks, 0);
    for (int contid = 0; contid < nconts; ++contid)
    {
        int solved;
        vector<int> tasks;
        for (int itask = 0; itask < ntasks; ++itask)
        {
            cin >> solved;
            if (solved == 1) 
            {
                ++v_task_nsolved[itask];
                tasks.push_back(itask);
            }
        }
        vcont.push_back(cont_t{ contid, tasks, 0 });
    }

    for (cont_t& cont: vcont)
    {
        for (int task: cont.tasks_solved)
            cont.score += nconts - v_task_nsolved[task];
    }

    sort(vcont.begin(), vcont.end(), 
         [](const cont_t& c1, const cont_t& c2)
         {
            if (c1.score > c2.score)
                return true;
            if (c1.score < c2.score)
                return false;
            
            if (c1.tasks_solved.size() > c2.tasks_solved.size())
                return true;
            if (c1.tasks_solved.size() < c2.tasks_solved.size())
                return false;

            return (c1.id < c2.id);
         });

    auto philip = find_if(vcont.begin(), vcont.end(), 
                         [pid](const cont_t& c){ return c.id == pid - 1; });

    cout << philip->score << " " << philip - vcont.begin() + 1;

    return 0;
}
