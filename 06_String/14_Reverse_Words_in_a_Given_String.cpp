// All Important Header Files
#include <bits/stdc++.h>
//ALL IMPORTANT MACROS
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define deb(x) cout << x << endl;
#define display(start, end) for (int i = start; i < end; i++)
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a, n) a, a + n
#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
//USING NAME SPACE
using namespace std;
//SOME TYPEDEF DECLARATION
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
// CODE WRITTEN BY KRISHNA_6431
int main()
{
    ll t, n, q;
    cin >> t >> n >> q;
    while (t-- != 0)
    {
        vector<ll> a;

        cout << "1 2 3" << endl;

        ll size = 3;
        ll p;
        cin >> p;
        if (p == 2)
        {
            a.push_back(1);
            a.push_back(2);
            a.push_back(3);
        }
        else if (p == 3)
        {
            a.push_back(1);
            a.push_back(3);
            a.push_back(2);
        }
        else
        {
            a.push_back(2);
            a.push_back(1);
            a.push_back(3);
        }
        for (ll i = 4; i <= (n); i++)
        {
            ll u = 0;
            ll v = size - 1;
            while (u < v)
            {
                ll mid = u + ((v - u) / 2);
                cout << a[mid] << " " << a[mid + 1] << " " << (i) << endl;
                cin >> p;
                if (p == a[mid])
                {
                    v = mid;
                }
                else if (p == a[mid + 1])
                {

                    u = mid + 1;
                }
                else
                {
                    a.insert(a.begin() + mid + 1, i);
                    size++;
                    break;
                }
            }
            if (size != i)
            {
                if (u == 0)
                {
                    a.insert(a.begin(), i);
                }
                else
                {
                    a.push_back(i);
                }
                size++;
            }
        }
        for (auto zzz : a)
        {
            cout << zzz << " ";
        }
        cout << endl;
        cin >> p;
        if (p == -1)
        {
            break;
        }
    }
}