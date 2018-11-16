#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(const int n,const int k,const int r_q,const int c_q,const vector<int>& obstacles) {

    int up, down, left, right, upLeft, upRight, downLeft, downRight;

    up =




}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n, k, r_q, c_q;
    scanf("%d %d $d $d", &n, &k, &r_q, &c_q);

    vector<int> obstacles = {0, n, n, 0};
    //left, right, up, down,

    int r_o, c_o;

    while(scanf("%d %d", r_o, c_o) != EOF && k--){
        if (c_o < c_q){ //left of queen
            if (r_o == r_q) //even with queen
                if (c_o > obstacles[0]) //closest to queen
                    obstacles[0] = c_o;
        } else if (c_o == c_q){ //centered on queen
            if (r_o < r_q) // down
                if (r_o > obstacles[3]) //closest to queen
                    obstacles[3] = r_o;
                else           // up
                if (r_o < obstacles[2])
                    obstacles[2] = r_o;
        } else { //right of queen
            if (r_o == r_q) //even with queen
                if (c_o < obstacles[0]) // closest to queen
                    obstacles[1] = c_o;
        }
    }


    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
