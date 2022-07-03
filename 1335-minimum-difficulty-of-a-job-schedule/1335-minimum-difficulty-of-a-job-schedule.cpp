class Solution {
public:
    #define ll long long int
    
    #define vi vector<int>
    #define vll vector<ll>
    #define vb vector<bool>
    
    #define vvi vector<vi>
    #define vvll vector<vll>
    #define vvb vector<vb>
    
    #define umapll_ll unordered_map<ll, ll>
    #define umapi_i unordered_map<int, int>
    #define umapll_b unordered_map<ll, bool>
    
    #define INF (1e9+7)
    
    //--------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------
    // RECURSION APPROACH 1:
    // jobDifficulty => JD[job number or job idx] = jobDifficulty_of_job_idx
    // d => number of days in total
        
    // state variables :
        // 1. d = the number of days left
        // 2. the idx of the first job done on that particular day
    // state : the difficulty of the job schedule given i days left and jth job being the first job on that day
    
    // rec rel : res = min([the cost for d-1 days with the job on those days starting on sched + 1] + 
        // current_max JD for today (when there are d days left))
    // for all k going from the next job idx to total_jobs left - 1
    
    unordered_map<ll, umapll_ll> dp_mem;
    ll top_down(ll d, ll j, vi &JD, ll tot_d){
        // N = total number of jobs
        ll N = JD.size();

        // if the number of days left are 0 and we are done with and we have completed all the jobs then we must NOT seach for any more jobs so return 0
        if(d == 0 and j == N) return 0;
        
        // else if we do not have any more days left and we are still left with jobs return INF
        // or if we have used up all the available jobs and now dont have any jobs left for the remaining days
        if(d == 0 or j == N) return INF;
        
        // memoized
        if(dp_mem.find(d) != dp_mem.end() and dp_mem[d].find(j) != dp_mem[d].end()) 
            return dp_mem[d][j];
        
        ll current_max = (ll)JD[j];
        ll res = INF;
        for(auto sched = j; (N - sched - 1) >= d-1 ; sched++){
            // sched indicates the last job idx done "today"
            // N - sched - 1 = number of jobs left
            // d-1 = the number of days left excluding today
            current_max = max(current_max, (ll) JD[sched]);
            res = min(res, top_down(d-1, sched + 1, JD, tot_d) + current_max);
        }
        return dp_mem[d][j] = res;
    }
    
    //--------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------
    // RECURSION APPROACH 2:
    // rec relation:
    // function dp(i, d) : the minimum cost of job schedule which starts on job i on day d
    vvll dp;
    int bottom_up(vi &JD, ll tot_days)
    {
        ll num_jobs = JD.size();
        dp.resize(num_jobs, vll (tot_days+1, INF));
        
        // BASE CASE:
        dp[num_jobs - 1][tot_days] = JD[num_jobs-1];
        // on the last day difficulty of day (for jobs from idx i to numjobs-1) 
        for(auto i = num_jobs-2; i >= 0; i--) dp[i][tot_days] = max(dp[i+1][tot_days], (ll) JD[i]);
        
        for(auto day = tot_days - 1; day > 0; day--){
            for(auto i = day-1; i < num_jobs - (tot_days - day); i++)
            {
                ll curr_max = 0;
                for(auto j = i; j < num_jobs - (tot_days - day); j++){
                    curr_max = max(curr_max, (ll)JD[j]);
                    dp[i][day] = min(dp[i][day], dp[j+1][day+1] + curr_max); 
                }
            }
        }
        return (int) dp[0][1];
        
    }
    
    //--------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------

    int minDifficulty(vi& jobDifficulty, int d) {
        dp_mem.clear();
        if(jobDifficulty.size() < d) return -1;
        // return (int)top_down((ll)d, 0, jobDifficulty, (ll)d);
        return bottom_up(jobDifficulty, (ll)d);
    }
};