#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
const ll MOD = 1e9+7, INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        map<string, pair<char[3], char[3]>> vars;
        map<string, string> vars2;
        map<string, ll> num_of_haha;

        int n;
        cin >> n;

        string var, type, data, first_var, second_var, trash;
        /**
         * var -> variable name
         * type -> := or =
         * if type is := then data will be the data stored in var
         * if type is = then first_var will be first argument and second_var will be second argument in a + b;
         * trash -> the + between a + b;
         */

        while (n--)
        {
            cin >> var >> type;
            if (type == ":=")
            {
                cin >> data;
                int size = data.size();

                for (int i = 0; i < 3 && i < size; ++i)
                {
                    // Insert data to first
                    vars[var].first[i] = data[i];

                    // Insert data to second
                    vars[var].second[i] = data[size-i-1];
                }

                for (int i = size; i < 3; ++i)
                {
                    // Fill unfilled data of first, if any
                    vars[var].first[i] = '0';

                    // Fill unfilled data of second, if any
                    vars[var].second[i] = '0';
                }

                // Count how many "haha" are there in the string
                int haha_count = 0;
                for (int i = 0; i < size - 3; i++)
                {
                    if ((data[i] == 'h' && data[i+1] == 'a') && (data[i+2] == 'h' && data[i+3] == 'a'))
                        ++haha_count;
                }
                num_of_haha[var] = haha_count;

                //cout << "\n" << var << " " << type << " " << data;
            }
            else
            {
                cin >> first_var >> trash >> second_var;

                char first_str[3];
                char second_str[3];
                for (int i = 0; i < 3; ++i)
                {
                    first_str[i] = vars[first_var].second[i];
                    second_str[i] = vars[second_var].first[i];
                }

                /**
                 * usahd -> first  = usa
                 *       -> second = dha
                 * usahd + usahd = ahd + usa
                 * 
                 * Index: 2 1 0 + 0 1 2
                 */

                int new_haha = 0;
                new_haha += (int)((first_str[2] == 'h' && first_str[1] == 'a') && (first_str[0] == 'h' && second_str[0] == 'a'));
                new_haha += (int)((first_str[1] == 'h' && first_str[0] == 'a') && (second_str[0] == 'h' && second_str[1] == 'a'));
                new_haha += (int)((first_str[0] == 'h' && second_str[0] == 'a') && (second_str[1] == 'h' && second_str[2] == 'a'));
                
                for (int i = 0, second_str_start = 0, first_str_end = 0; i < 3; i++)
                {
                    vars[var].first[i] = vars[first_var].first[i];
                    // If data is empty, fill it with the beginning of second str, because duhh
                    if (vars[var].first[i] == '0')
                    {
                        vars[var].first[i] = second_str[second_str_start];
                        second_str_start++;
                    }

                    vars[var].second[i] = vars[second_var].second[i];
                    // If data is empty, fill it with the end of first str, because reason
                    if(vars[var].second[i] == '0')
                    {
                        vars[var].second[i] = first_str[first_str_end];
                        first_str_end++;
                    }
                }
                
                num_of_haha[var] = num_of_haha[first_var] + num_of_haha[second_var] + new_haha;

                //cout << "\n" << var << " " << type << " " << first_var << " + " << second_var << "\n";
            }
            
            /*
            for (auto i:vars)
            {
                cout << "\n";
                cout << i.first << "\n"; 
                cout << "First: " << i.second.first[0] << i.second.first[1] << i.second.first[2] << "\n";
                cout << "Second: " << i.second.second[0] << i.second.second[1] << i.second.second[2] << "\n";
                cout << "Num of haha: " << num_of_haha[i.first] << "\n";
            }
            */
        }
        cout << num_of_haha[var] << "\n";
    }
}
