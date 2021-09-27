#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const unsigned int M = 1000000007;

static vector<int> SearchString(string text, string pattern, int k)
{   
    vector<int> res;
    int result = -1;
    int m = pattern.size();
    unsigned long *R;
    unsigned long patternMask[CHAR_MAX + 1];
    int i, d;
    if (pattern[0] == '\0') return {};
    if (m > 31) 
        return {-1};
    R = new unsigned long[(k + 1)];
    for (i = 0; i <= k; ++i)
        R[i] = ~1;
    for (i = 0; i <= CHAR_MAX; ++i)
        patternMask[i] = ~0;
    for (i = 0; i < m; ++i)
        patternMask[pattern[i]] &= ~(1UL << i);
    for (i = 0; text[i] != '\0'; ++i)
    {
        unsigned long oldRd1 = R[0];
        R[0] |= patternMask[text[i]];
        R[0] <<= 1;
        for (d = 1; d <= k; ++d)
        {
            unsigned long tmp = R[d];
            R[d] = (oldRd1 & (R[d] | patternMask[text[i]])) << 1;
            oldRd1 = tmp;
        }
        if (0 == (R[k] & (1UL << m)))
        {
            result = (i - m) + 1;
            res.push_back(result);
        }
    }
    delete[] R;
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    string data="Porter's Five Force Model for Apple Essay ...Apple Inc. Apple Inc. (formerly Apple Computer, Inc.) is an American multinational corporation that designs and sells consumer electronics, computer software, and personal computers. The company's best-known hardware products are the Macintosh line of computers, the iPod, the iPhone and the iPad. Its software includes the OS X and iOS operating system; the iTunes media browser; and the iLife and iWork creativity and production suites. Apple is the ...";
    cout<<"Enter The pattern to search";
    string pattern;
    cin>>pattern;
    vector<int> indices;
     indices=SearchString(data,pattern, 1);
     vector<pair<int,string>> results;
    for(int i: indices){
        int j=i;
        string match;
        while(data[j]!=' '){
            match.push_back(data[j]);
            j++;
        }
        results.push_back({i,match});
    }
    for(auto i:results){
        cout<<"Index->"<<i.first<<":"<<i.second<<'\n';
    }
}