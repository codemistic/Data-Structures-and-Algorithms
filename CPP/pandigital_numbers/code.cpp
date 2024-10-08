#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

vector<int> func3(string str, vector<int> &values)
{
    int num = stoi(str);
    int a, b;
    b = num % 10;
    num /= 10;
    a = num % 10;
    num /= 10;

    vector<int> vec;

    for (int i = 0; i < values.size(); i++)
    {
        if (values[i] == 0)
        {
            if ((i + a + b) % 3 == 0)
            {
                vec.push_back(i);
            }
        }
    }
    return vec;
}

vector<int> func5(string str, vector<int> &values)
{
    int num = stoi(str);
    int a, b;
    b = num % 10;
    num /= 10;
    a = num % 10;
    num /= 10;

    vector<int> vec;

    for (int i = 0; i < values.size(); i++)
    {
        if (values[i] == 0 && (i == 0 || i == 5))
        {
            vec.push_back(i);
        }
    }

    return vec;
}

vector<int> func7(string str, vector<int> &values)
{
    int num = stoi(str);
    int a, b;
    b = num % 10;
    num /= 10;
    a = num % 10;
    num /= 10;

    vector<int> vec;

    for (int i = 0; i < values.size(); i++)
    {
        // Subtracting 2 times the last digit from the rest gives a multiple of 7. (Works because 21 is divisible by 7.)
        if (((a * 10 + b) - (2 * i)) % 7 == 0 && values[i] == 0)
        {
            vec.push_back(i);
        }
    }

    return vec;
}

vector<int> func11(string str, vector<int> &values)
{
    int num = stoi(str);
    int a, b;
    b = num % 10;
    num /= 10;
    a = num % 10;
    num /= 10;

    vector<int> vec;

    for (int i = 0; i < values.size(); i++)
    {
        if ((abs(a + i - b)) % 11 == 0 && values[i] == 0)
        {
            vec.push_back(i);
        }
    }

    return vec;
}

vector<int> func13(string str, vector<int> &values)
{
    int num = stoi(str);
    int a, b;
    b = num % 10;
    num /= 10;
    a = num % 10;
    num /= 10;

    vector<int> vec;

    for (int i = 0; i < values.size(); i++)
    {
        // Subtract the last two digits from four times the rest. The result must be divisible by 13.
        if ((abs(b * 10 + i - 4 * a)) % 13 == 0 && values[i] == 0)
        {
            vec.push_back(i);
        }
    }

    return vec;
}

vector<int> func17(string str, vector<int> &values)
{
    int num = stoi(str);
    int a, b;
    b = num % 10;
    num /= 10;
    a = num % 10;
    num /= 10;

    vector<int> vec;

    for (int i = 0; i < values.size(); i++)
    {
        // Subtract 5 times the last digit from the rest.

        if ((abs(a * 10 + b - 5 * i)) % 17 == 0 && values[i] == 0)
        {
            vec.push_back(i);
        }
    }

    return vec;
}

void func(int n)
{
    // 406
    string str = to_string(n);
    vector<int> values(10, 0);

    // vec[0] = vec[4] = vec[6] = 1;

    int a, b, c;
    c = n % 10;
    n /= 10;
    b = n % 10;
    n /= 10;
    a = n % 10;
    n /= 10;

    values[a] = values[b] = values[c] = 1;

    vector<int> vec3 = func3(str, values);

    for (int i = 0; i < vec3.size(); i++)
    {
        string stri = str;
        stri = stri + to_string(vec3[i]);

        values[vec3[i]] = 1;

        // cout << "STRI: " << stri << endl;

        // cout << "CHECK VECTOR: " << endl;
        // for (int i = 0; i < values.size(); i++)
        // {
        //     cout << values[i] << " ";
        // }
        // cout << endl;

        vector<int> vec5 = func5(stri, values);

        for (int j = 0; j < vec5.size(); j++)
        {
            string strj = stri;
            strj = strj + to_string(vec5[j]);

            values[vec5[j]] = 1;

            // cout << "STRJ: " << strj << endl;

            // cout << "CHECK VECTOR: " << endl;
            // for (int i = 0; i < values.size(); i++)
            // {
            //     cout << values[i] << " ";
            // }
            // cout << endl;

            vector<int> vec7 = func7(strj, values);

            for (int k = 0; k < vec7.size(); k++)
            {

                string strk = strj;
                strk = strk + to_string(vec7[k]);

                values[vec7[k]] = 1;

                // cout << "STRK: " << strk << endl;

                // cout << "CHECK VECTOR: " << endl;
                // for (int i = 0; i < values.size(); i++)
                // {
                //     cout << values[i] << " ";
                // }
                // cout << endl;

                vector<int> vec11 = func11(strk, values);

                for (int l = 0; l < vec11.size(); l++)
                {

                    string strl = strk;
                    strl = strl + to_string(vec11[l]);

                    values[vec11[l]] = 1;

                    // cout << "STRL: " << strl << endl;

                    vector<int> vec13 = func13(strl, values);

                    for (int m = 0; m < vec13.size(); m++)
                    {

                        string strm = strl;
                        strm = strm + to_string(vec13[m]);

                        values[vec13[m]] = 1;

                        // cout << "STRM: " << strm << endl;

                        vector<int> vec17 = func17(strm, values);

                        for (int n = 0; n < vec17.size(); n++)
                        {

                            string strn = strm;
                            strn = strn + to_string(vec17[n]);

                            values[vec17[n]] = 1;

                            // cout << "STRM: " << strn << endl;

                            // cout << "CHECK VECTOR: " << endl;
                            // for (int i = 0; i < values.size(); i++)
                            // {
                            //     cout << values[i] << " ";
                            // }
                            // cout << endl;

                            for (int a = 0; a < values.size(); a++)
                            {
                                if (values[a] == 0)
                                {
                                    string abcd = to_string(a);
                                    string crst = abcd + strn;

                                    cout << "FINAL STRING: " << crst << endl;
                                }
                            }

                            values[vec17[n]] = 0;
                        }

                        // answer is size of vec17

                        values[vec13[m]] = 0;
                    }

                    values[vec11[l]] = 0;
                }

                values[vec7[k]] = 0;
            }

            values[vec5[j]] = 0;
        }
        values[vec3[i]] = 0;
    }
}

void solve()
{

    int start = 100, end = 1000;
    for (int i = start; i < end; i++)
    {
        int curr = i;
        if (curr % 2 == 0)
        {
            int a, b, c;
            a = curr % 10;
            curr /= 10;
            b = curr % 10;
            curr /= 10;
            c = curr % 10;
            curr /= 10;

            if (a != b && b != c && c != a)
            {
                // cout << i << endl;
                func(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin.exceptions(cin.failbit);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    clock_t start = clock();

    solve();
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    printf("Time measured: %.4f seconds.", elapsed);
    return 0;
}

/*





*/