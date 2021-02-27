// 华为机试训练105题 https://www.nowcoder.com/ta/huawei
// 84.8% 通过率， pass 89/105， fail 7/105.

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <strings.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

// namespace publicTime
// {
//     SYSTEMTIME st = {0};
//     GetLocalTime(&st);
// }

// #define CHECK_FALSE_RET(result) \
//     do\
//     { \
//     int temp = result    \
//     if (temp != ERR_SUCCESS) \
//         return temp;\
//     }\
//     while (0)

// #define SEND_ERRMSG_RET(ERR_CODE) \
//     do\
//     {\
//     cout << getErrMsg(ERR_CODE) << endl;\
//     return ERR_CODE;\
//     }\
//     while(0)

namespace comlib
{
    void strip(string &str, char c = ' ')
    {
        while (str.size() > 0)
        {
            if (str[0] == c)
            {
                str = str.substr(1);
            }
            else if(str[str.size() - 1] == c)
            {
                str = str.substr(0, str.size() - 1);
            }
            else
            {
                return ;
            }
        }
    }
}

//niuke 华为机试训练第一题 https://www.nowcoder.com/ta/huawei
// HJ1	字符串最后一个单词的长度	字符串	较难	26.27%
// 难度：*，技巧：*
//https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
namespace NiuKeHuaWeiTraining_001
{
    // #include <iostream>
    // #include <time.h>

    using namespace std;
    int solution1(void)
    {
        time_t tbegin, tend;
        tm* tblock;

        tbegin = time(NULL);
        tblock = localtime(&tbegin);
        cout << asctime(tblock) << endl;
        char input[5001];
        int size = 5000;
        cout << "Please input a string to find the length of last word: " << endl;
        // gets(input);
        cin.getline(input, size);
        string sInput(input);
        if (sInput.length() > 5001)
        {
            cout << "The string you input is longer than 5000, actual length is: " << sInput.length() << endl;
            return 0;
        }

        string sOutput;
        int result(0);
        if (sInput.find(" ") != std::string::npos)
        {
            sOutput = sInput.substr(sInput.find_last_of(" ") + 1);
            result = sOutput.length();
        }
        else
        {
            result = sInput.length();
        }

        cout << result << endl;

        time(&tend);
        cout << "The process ran " << difftime(tend, tbegin) << " seconds." << endl;

        return result;
    }

    int solution2(void)
    {
        string input;
        while(std::cin >> input);  // ctrl + z/c 结束当前测试
        cout << input.size() << endl;

        return 0;
    }
}

// HJ2	计算字符个数	字符串哈希	较难	24.49%
// 难度：*，技巧：*
// https://www.nowcoder.com/practice/a35ce98431874e3a820dbe4b2d0508b1?tpId=37&&tqId=21225&rp=1&ru=/ta/huawei&qru=/ta/huawei/question-ranking
namespace NiuKeHuaWeiTraining_002
{
    // #include <iostream>
    // #include <map>
    // #include <stdio.h>
    using namespace std;
    int solution1(void)
    {
        string str;
        getline(cin, str);

        char c;
        cin >> c;

        map<char,int> mStr;

        int i = 0;
        while(str[i])
        {
            mStr[tolower(str[i])]++;
            i++;
        }

        cout << mStr[tolower(c)] << endl;

        return 0;
    }
}

// HJ3	明明的随机数	数组	较难	17.47%
// namespace NiuKeHuaWeiTraining_003
// {
//     int solution1(void)
//     {
//         return 0;
//     }
// }

// HJ4	字符串分隔	字符串	较难	23.58%
// 难度：*
namespace NiuKeHuaWeiTraining_004
{
    // #include <iostream>
    // #include <string>

    // using namespace std;

    int solution1(void)
    {
        string str;
        while (cin >> str)
        {
            int len = str.size();
            int i(0);
            int j(0);
            while (j < str.size())
            {
                j = i + 8;
                for (; i < j; i++)
                {
                    if (i < str.size())
                    {
                        cout << str[i];
                    }
                    else
                    {
                        cout << '0';
                    }
                }
                cout << endl;
            }
        }
        return 0;
    }

    int solution2(void)
    {
        string str;
        while (cin >> str)
        {
            int left = str.size() % 8;
            while (str.size() >= 8)
            {
                cout << str.substr(0,8) << endl;
                str = str.substr(8);
            }
            if (left)
            {
                int rest = 8 - left;
                str = str.append(rest, '0');
                cout << str << endl;
            }
        }
        return 0;
    }

    int solution3(void)
    {
        string str;
        while (cin >> str)
        {
            while (str.size() > 8) // 注意这里不能等于8
            {
                cout << str.substr(0,8) << endl;
                str = str.substr(8);
            }
            str.resize(8, '0');  // resize 可还行
            cout << str << endl;
        }
        return 0;
    }

    int solution4(void)
    {
        string str;
        while (cin >> str)
        {
            int len = str.size();
            for (int i = 0; i < len; i += 8)
            {
                cout.width(8); // width和fill赞一个！
                cout.fill('0');
                cout << left << str.substr(i, 8) << endl;
            }
            str.clear();
        }
        return 0;
    }
}

// HJ5	进制转换	字符串	中等	26.52%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_005
{
    // #include <iostream>
    // #include <strings.h>
    // using namespace std;

    int solution1(void)
    {
        string str;
        while (cin >> str)
        {
            if (strncasecmp(str.c_str(), "0x", 2) == 0)
            {
                str = str.substr(2);
            }
            int i = 0;
            int num(0);
            while (i < str.size())
            {
                if ((str[i] >= '0') && (str[i] <= '9'))
                {
                    num = int(str[i] - '0') + num * 16;
                }
                else if ((str[i] >= 'a') && (str[i] <= 'f'))
                {
                    num = num * 16 + int(str[i] - 'a') + 10;
                }
                else if ((str[i] >= 'A') && (str[i] <= 'F'))
                {
                    num = num * 16 + int(str[i] - 'A') + 10;
                }
                else
                {
                    cout << "input illegal!" << endl;
                    exit(0);
                }
                
                i++;
            }
            cout << num << endl;
            str.clear();
        }
        return 0;
    }

    int solution2(void)
    {
        int str;
        while(cin >> hex >> str)
        {
            cout << dec << str << endl;
        }
        return 0;
    }
}

// HJ6	质数因子	排序	中等	27.37%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_006
{
    int solution1(void)
    {
        long num;
        while (cin >> num)
        {
            vector<long> factor;
            int i = 2;
            // int max = (int)pow(num, 0.5);
            while (i <= (int)pow(num, 0.5))
            {
                if (num % i == 0)
                {
                    factor.push_back(i);
                    num /= i;
                    continue;
                }
                i++;
            }
            factor.push_back(num);

            for (vector<long>::iterator it = factor.begin(); it != factor.end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }

        return 0;
    }
}

// HJ7	取近似值	数学	入门	42.89%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_007
{
    // #include <iostream>
    // #include <string>

    // using namespace std;
    int solution1(void)
    {
        float i;
        scanf("%f", &i);
        int j = i * 10;  // 可以直接用int(i)强制取整
        int k = j % 10;
        if (k >= 5)
        {
            j = j / 10 + 1;
        }
        else
        {
            j /= 10;
        }

        cout << j << endl;

        return 0;
    }

    int solution2(void)
    {
        float i;
        scanf("%f", &i);
        cout << int(i + 0.5) << endl;
        return 0;
    }
}

// HJ8	合并表记录		中等	29.74%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_008
{
    int solution1(void)
    {
        int count = 0;
        cin >> count;
        map<int, int> mTable;
        mTable.clear();
        while (count--)
        {
            int index = 0, value = 0;
            cin >> index >> value;
            mTable[index] += value;
        }

        for (map<int, int>::iterator it = mTable.begin(); it != mTable.end(); it ++)
        {
            cout << it->first << " " << it->second << endl;
        }

        return 0;
    }
}

// HJ9	提取不重复的整数	数组哈希位运算	中等	35.22%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_009
{
    int solution1(void)
    {
        int num = 0;
        cin >> num;
        int count[10] = {0};
        while (num)
        {
            if (count[num % 10] == 0)
            {
                cout << num % 10;
                count[num % 10]++;
                num /= 10;
                continue;
            }
            else
            {
                num /= 10;
                continue;
            }
        }
        cout << endl;
        return 0;
    }
}

// HJ10	字符个数统计	字符串哈希	中等	38.00%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_010
{
    int solution1(void)
    {
        string str;
        cin >> str;
        int arr[128] = {0};
        for (unsigned int i = 0; i < str.size(); i++)
        {
            if (str[i] < 128)
            {
                arr[str[i]]++;
            }
        }
        int sum = 0;
        for (unsigned int i = 0; i < 128; i++)
        {
            if (arr[i])
            {
                sum++;
            }
        }

        cout << sum << endl;

        return 0;
    }
}

// HJ11	数字颠倒	字符串	简单	49.75%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_011
{
    int solution1(void)
    {
        int input(0);
        scanf("%d", &input);
        while(input)
        {
            cout << input % 10;
            input /= 10;
        }
        cout << endl;
        return 0;
    }

    int solution2(void)
    {
        // #include <algorithm>
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        cout << str << endl;
        return 0;
    }
}

// HJ12	字符串反转	字符串	简单	49.97%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_012
{
    int solution1(void)
    {
        string str;
        // scanf("%s", str);
        cin >> str;
        reverse(str.begin(), str.end());
        cout << str << endl;
        return 0;
    }
}

// HJ13	句子逆序	数组	较难	31.79%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_013
{
    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            vector<string> v;
            int i = 0, j = 0;
            for (; i < str.size(); i++)
            {
                for (j = 1; i + j <= str.size(); j++)
                {
                    if (i + j == str.size())
                    {
                        if (str[i + j - 1] != ' ')
                            v.push_back(str.substr(i, j));
                        break;
                    }
                    else if (str[i + j] == ' ')
                    {
                        v.push_back(str.substr(i, j));
                        break;
                    }
                }
                i = j + i;
            }
            
            for (vector<string>::iterator iter = v.end() - 1; iter != v.begin(); iter--)
            {
                cout << *iter << ' ';
            }
            cout << v.at(0) << endl;
        }
        return 0;
    }
}

// HJ14	字符串排序	字符串	中等	34.50%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_014
{
    int solution1(void)
    {
        int num;
        cin >> num;
        vector<string> vString;
        while (num--)
        {
            string str;
            cin >> str;
            vString.push_back(str);
        }
        sort(vString.begin(), vString.end());
        for (vector<string>::iterator it = vString.begin(); it != vString.end(); it++)
        {
            cout << *it << endl;
        }

        return 0;
    }


    void strSort(vector<string> &vStr)
    {
        for (int i = 0; i < vStr.size(); i++)
        {
            for (int j = i + 1; j < vStr.size(); j++)
            {
                if (vStr[i] > vStr[j])
                {
                    swap(vStr[i], vStr[j]);
                }
            }
        }
        return;
    }

    int solution2(void)
    {
        int num;
        cin >> num;
        vector<string> vString;
        while (num--)
        {
            string str;
            cin >> str;
            vString.push_back(str);
        }

        strSort(vString);

        for (vector<string>::iterator it = vString.begin(); it != vString.end(); it++)
        {
            cout << *it << endl;
        }
        return 0;
    }
}

// HJ15	求int型数据在内存中存储时1的个数	位运算	入门	48.51%
// 难度：*，技巧：**
namespace NiuKeHuaWeiTraining_015
{
    // #include <iostream>

    // using namespace std;
    int solution1(void)
    {
        int i;
        scanf("%d", &i);
        // cin >> i;
        
        int num(0);
        while (i)
        {
            num += (i & 0x1);
            i >>= 1;
        }
        
        cout << num << endl;
        
        return 0;
    }

    int solution2(void)
    {
        int i;
        // scanf("%d", &i);
        cin >> i;
        
        int num(0);
        while (i)
        {
            // 如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。
            // 其余所有位将不会受到影响。
            i &= (i - 1);
            num++;
        }
        
        cout << num << endl;
        
        return 0;
    }
}

// HJ16	购物单	动态规划	中等	16.51%
// 难度：*，技巧：*
// namespace NiuKeHuaWeiTraining_016
// {
//     int solution1(void)
//     {
//         return 0;
//     }
// }

// HJ17	坐标移动	字符串	较难	18.06%
// 难度：*，技巧：*, 提交一次过
namespace NiuKeHuaWeiTraining_017
{
    // #include <iostream>
    // #include <strings.h>
    // using namespace std;

    string removeStr(string &str, char c = ' ')
    {
        while (str.size() > 0)
        {
            if (str.find(c) != std::string::npos)
            {
                if (str.find(c) != str.size() - 1)
                {
                    str = str.substr(0, str.find_first_of(c)) + str.substr(str.find_first_of(c) + 1);
                }
                else
                {
                    str = str.substr(0, str.find_first_of(c));
                }
            }
            else
            {
                break;
            }
        }
        return str;
    }

    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            int pos[2] = {0, 0};
            while (str.size() > 0)
            {
                string cmd;
                if (str.find(";") != std::string::npos)
                {
                    cmd = str.substr(0, str.find_first_of(';'));
                    str = str.substr(str.find_first_of(';') + 1);
                }
                else
                {
                    cmd = str;
                }
                
                removeStr(cmd);
                if (cmd.size() <= 1)
                {
                    continue;
                }

                if (cmd.substr(1).size() > 2)
                {
                    continue;
                }
                else if (cmd.substr(1).size() > 1 && (cmd[2] < '0' || cmd[2] > '9'))
                {
                    continue;
                }
                else if(cmd[1] < '0' || cmd[1] > '9')
                {
                    continue;
                }
                
                char ctrl = cmd[0];
                int steps = stoi(cmd.substr(1));
                
                if (steps < 0 || steps > 99)
                {
                    continue;
                }
                if (ctrl == 'A')
                {
                    pos[0] -= steps;
                }
                else if (ctrl == 'D')
                {
                    pos[0] += steps;
                }
                else if (ctrl == 'W')
                {
                    pos[1] += steps;
                }
                else if (ctrl == 'S')
                {
                    pos[1] -= steps;
                }
                else
                {
                    continue;
                }
            }
            cout << pos[0] << "," << pos[1] << endl;
        }
        return 0;
    }
}

// HJ18	识别有效的IP地址和掩码并进行分类统计	字符串	困难	18.72%
// 难度：**，技巧：**, pass
namespace NiuKeHuaWeiTraining_018
{
    // #include <arpa/inet.h>
    // int solution1(void)
    // {
    //     // strtok(tok, "~");
    //     // int valid = inet_pton(AF_INET,p[0],(void *)&s);
    //     return 0;
    // }

    // #include <iostream>
    // #include <vector>
    // #include <algorithm>
    using namespace std;

    struct IP
    {
        int ipAdress[4];
        int mask[4];
    };

    const vector <int> validMask = {0, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF};

    bool checkAddress(int n)
    {
        if (n < 0 || n > 256)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool checkMask(int n)
    {
        if (find(validMask.begin(), validMask.end(), n) == validMask.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool checkSubAddress(IP &ip, int startIndex)
    {
        for (int i = startIndex; i < 4; i++)
        {
            if (!checkAddress(ip.ipAdress[i]))
            {
                return false;
            }
        }
        return true;
    }

    int solution1(void)
    {
        string str;
        vector <IP> ips;
        
        ips.clear();
        unsigned int result[7] = {0};
        while (getline(cin, str))
        {
            int num[8] = {0};
            for (int i = 0; i < 8; i++)
            {
                string s;

                if (i == 3)
                {
                    if (str[0] != '~')
                    {
                        s = str.substr(0, str.find('~'));
                    }
                    else 
                    {
                        s = "";
                    }
                }
                else if (i != 7)
                {
                    s = str.substr(0, str.find('.'));
                }
                else
                {
                    s = str;
                }
                int temp = -1;
                if (s != "")
                {
                    temp = stoi(s);
                }
                if (i == 3)
                {
                    str = str.substr(str.find('~') + 1);
                }
                else if (i != 7)
                {
                    str = str.substr(str.find('.') + 1);
                }
                num[i] = temp;
            }
            ips.push_back({num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7]});
        }
        
        for (vector<IP>::iterator iter = ips.begin(); iter < ips.end(); iter++)
        {
            // check mask first;
            unsigned int mask = 0;
            mask = (iter->mask[0] << 24) | (iter->mask[1] << 16) | (iter->mask[2] << 8) | (iter->mask[3]);
            if (mask == 0xFFFFFFFF || mask == 0)
            {
                result[5]++;
                continue;
            }
            mask = ~mask + 1;
            if (mask & (mask - 1))
            {
                result[5]++;
                continue;
            }
            
            if (iter->ipAdress[0] == 0 || iter->ipAdress[0] == 127)
            {
                continue;
            }
            
            if (iter->ipAdress[0] == 10 || (iter->ipAdress[0] == 192 && iter->ipAdress[1] == 168) ||
            (iter->ipAdress[0] == 172 && (iter->ipAdress[1] >= 16 && iter->ipAdress[1] < 32))) // Address type private
            {
                if ((iter->ipAdress[0] == 10 && (!checkAddress(iter->ipAdress[1]) || 
                                                !checkAddress(iter->ipAdress[2]) || !checkAddress(iter->ipAdress[3]))) ||
                    ((iter->ipAdress[0] == 192 || iter->ipAdress[0] == 172) && 
                    (!checkAddress(iter->ipAdress[2]) || !checkAddress(iter->ipAdress[3]))))
                    
                {
                    result[5]++;
                }
                else
                {
                    result[6]++;
                }
            }
            
            if (iter->ipAdress[0] >= 1 && iter->ipAdress[0] < 127) // Address type A
            {
                if (!checkSubAddress(*iter, 1))
                {
                    result[5]++;
                }
                else
                {
                    result[0]++;
                }
            }
            else if (iter->ipAdress[0] >= 128 && iter->ipAdress[0] < 192) // Address type B
            {
                if (!checkAddress(iter->ipAdress[1]) ||
                    !checkAddress(iter->ipAdress[2]) ||
                    !checkAddress(iter->ipAdress[3]))
                {
                    result[5]++;
                }
                else
                {
                    result[1]++;
                }
            }
            else if (iter->ipAdress[0] >= 192 && iter->ipAdress[0] < 224) // Address type C
            {
                if (!checkAddress(iter->ipAdress[1]) ||
                    !checkAddress(iter->ipAdress[2]) ||
                    !checkAddress(iter->ipAdress[3]))
                {
                    result[5]++;
                }
                else
                {
                    result[2]++;
                }
            }
            else if (iter->ipAdress[0] >= 224 && iter->ipAdress[0] < 240) // Address type D
            {
                if (!checkAddress(iter->ipAdress[1]) ||
                    !checkAddress(iter->ipAdress[2]) ||
                    !checkAddress(iter->ipAdress[3]))
                {
                    result[5]++;
                }
                else
                {
                    result[3]++;
                }
            }
            else if (iter->ipAdress[0] >= 240 && iter->ipAdress[0] < 256) // Address type E
            {
                if (!checkAddress(iter->ipAdress[1]) ||
                    !checkAddress(iter->ipAdress[2]) ||
                    !checkAddress(iter->ipAdress[3]))
                {
                    result[5]++;
                }
                else
                {
                    result[4]++;
                }
            }
        }
        
        for (int i = 0; i < 6; i++)
        {
            cout << result[i] << " ";
        }
        cout << result[6] << endl;
        
        return 0;
    }
}

// HJ19	简单错误记录	字符串	困难	16.56%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_019
{
    struct ERR
    {
        string msg;
        unsigned int line;
        unsigned int count;
    };

    int solution1(void)
    {
        vector<ERR> err;
        vector<ERR> errOut;
        err.clear();
        errOut.clear();
        
        string str;
        unsigned int line;
        
        while (getline(cin, str))
        {
            int temp = 0;
            string s;
            if (str.find('\\') != std::string::npos)
            {
                s = str.substr(str.find_last_of('\\') + 1); // NOTES: here we can use rfind(), reverse of find().
            }
            else
            {
                s = str;
            }
            
            line = stoi(s.substr(s.find(' ') + 1));
            s = s.substr(0, s.find(' '));
            
            if (s.size() > 16)
            {
                s = s.substr(s.size() - 16);
            }

            err.push_back({s, line, 1});
        }
        
        for (unsigned int i = 0; i < err.size(); i++) // TODO: dupicate here. Use find(err.begin(); err.end(); errRecord(msg, line, count))
        {
            if (err[i].msg == "")
            {
                continue;
            }
            bool duplicate = false;
            for (unsigned int j = i + 1; j < err.size(); j++)
            {
                if (err[i].msg == err[j].msg && err[i].line == err[j].line) // TODO: improvement: overwrite operator ==
                {
                    err[i].count++;
                    duplicate = true;
                    err[j].msg = "";
                }
            }
            
            errOut.push_back(err[i]);
        }
        
        int i = 0;
        i = (errOut.size() > 8 ? errOut.size() - 8 : 0);
        for (; i < errOut.size(); i++)
        {
            cout << errOut[i].msg << " " << errOut[i].line << " " << errOut[i].count << endl;
        }

        return 0;
    }
}

// HJ20	密码验证合格程序	数组字符串	较难	23.61%
// 难度：**，技巧：*， 注意 find_first_of与find的不同。。。
namespace NiuKeHuaWeiTraining_020
{
    // #include <iostream>
    // using namespace std;

    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            bool result = true;
            if (str.size() <= 8)
            {
                cout << "NG" << endl;
                continue;
            }
            
            bool pwTypes[4] = {false}; // pwTypes[0] -> UpperCase, [1]->LowerCase, [2]->digit, [3]->others
            
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                {
                    pwTypes[0] = true;
                }
                else if (str[i] >= 'a' && str[i] <= 'z')
                {
                    pwTypes[1] = true;
                }
                else if (str[i] >= '0' && str[i] <= '9')
                {
                    pwTypes[2] = true;
                }
                else
                {
                    pwTypes[3] = true;
                }
            }
            
            for (int i = 0; i < str.size(); i++)
            {
                for (int j = 3; j < str.size() - i; j++)
                {
                    string temp = str.substr(i, j);
                    // 注意： str.find_first_of(string temp)是在str中查找temp中的任何一个字符，只要找到，就返回这个字符的起始位置！！！因此这个不适合使用find_first_of
                    if (str.find(temp) != i)
                    {
                        result = false;
                        break;
                    }
                }
                if (result == false)
                {
                    break;
                }
            }
            
            if (result == false)
            {
                cout << "NG" << endl;
                continue;
            }
            
            int types = 0;
            types += (pwTypes[0] ? 1 : 0);
            types += (pwTypes[1] ? 1 : 0);
            types += (pwTypes[2] ? 1 : 0);
            types += (pwTypes[3] ? 1 : 0);
            if (types >= 3)
            {
                cout << "OK" << endl;
                continue;
            }
            else
            {
                cout << "NG" << endl;
                continue;
            }
        }
        return 0;
    }
}

// HJ21	简单密码破解	字符串	中等	34.26%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_021
{
    int solution1(void)
    {
        string str = "";
        while (cin >> str)
        {
            string sOutput = "";
            for (unsigned int i = 0; i < str.size(); i++)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                {
                    switch (str[i])
                    {
                        case 'a':
                        case 'b':
                        case 'c':
                            sOutput += '2';
                            break;
                        case 'd':
                        case 'e':
                        case 'f':
                            sOutput += '3';
                            break;
                        case 'g':
                        case 'h':
                        case 'i':
                            sOutput += '4';
                            break;
                        case 'j':
                        case 'k':
                        case 'l':
                            sOutput += '5';
                            break;
                        case 'm':
                        case 'n':
                        case 'o':
                            sOutput += '6';
                            break;
                        case 'p':
                        case 'q':
                        case 'r':
                        case 's':
                            sOutput += '7';
                            break;
                        case 't':
                        case 'u':
                        case 'v':
                            sOutput += '8';
                            break;
                        case 'w':
                        case 'x':
                        case 'y':
                        case 'z':
                            sOutput += '9';
                            break;
                        default:
                            break;
                    }
                }
                else if (str[i] >= 'A' && str[i] < 'Z')
                {
                    sOutput += (str[i] - 'A' + 1 + 'a');
                }
                else if (str[i] == 'Z')
                {
                    sOutput += 'a';
                }
                else
                {
                    sOutput += str[i];
                }
                
            }
            cout << sOutput << endl;
        }
        return 0;
    }
}

// HJ22	汽水瓶	模拟	简单	23.68%
// 难度：*，技巧：***
namespace NiuKeHuaWeiTraining_022
{
    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            int num = 0;
            while(n && n > 2)
            {
                num += n / 3;
                n = n / 3 + n % 3;
            }
            num += (n == 2 ? 1 : 0);
            cout << num << endl;
        }
        return 0;
    }

    int solution2(void)
    {
        int n = 0;
        // 当有2个空瓶时，就可以喝一瓶, 并且最后剩余0个空瓶
        // 把所有瓶按 2 分组，有多少组达到2个空瓶就可以喝多少瓶汽水，没达到的只有1瓶则不能喝。
        while (cin >> n)
        {
            cout << n / 2 << endl;
        }
        return 0;
    }
}

// HJ23	删除字符串中出现次数最少的字符	字符串	较难	25.63%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_023
{
    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            int arr[26] = {0};

            for (int i = 0; i < str.size(); i++)
            {
                arr[str[i] - 'a']++;
            }
            int min = INT32_MAX; // cannot be 0
            for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
            {
                if (arr[i])
                {
                    min = (min < arr[i] ? min : arr[i]);
                }
            }

            for (int i = 0; i < str.size(); i++)
            {
                if (arr[str[i] - 'a'] == min)
                {
                    if (i == 0)
                    {
                        str = str.substr(1);
                    }
                    else if (i == str.size() - 1)
                    {
                        str = str.substr(0, i - 1);
                    }
                    else
                    {
                        str = str.substr(0, i) + str.substr(i + 1);
                    }
                    i--;
                }
            }
            
            cout << str << endl;
        }
        return 0;
    }
}

// HJ24	合唱队	动态规划队列	较难	22.16%
// 难度：***，技巧：***， fail。 DP 问题！！
namespace NiuKeHuaWeiTraining_024
{
    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            vector<int> v(n, 0);
            for (auto &it : v)
            {
                cin >> it;
            }
            
            int count = n;
            vector<int> dp_1(n, 1);
            vector<int> dp_2(n, 1);
            for (int i = 0; i < n; i++)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (v[i] > v[j])
                    {
                        dp_1[i] = max(dp_1[i], 1 + dp_1[j]);
                    }
                }
            }
            
            reverse(v.begin(), v.end());
            for (int i = 0; i < n; i++)
            {
                for (int j = i - 1; j >= 0; j--) // 注意这里要先算前面的值，这样才能保证后面的值是正确的。
                {
                    if (v[i] > v[j])
                    {
                        dp_2[i] = max(dp_2[i], 1 + dp_2[j]);
                    }
                }
            }
            
            reverse(dp_2.begin(), dp_2.end());
            for (int i = 0; i < n; i++)
            {
                int tmp = n - dp_1[i] - dp_2[i] + 1;
                count = (count <= tmp ? count : tmp);
            }
            cout << count << endl;
        }
        return 0;
    }
}

// HJ25	数据分类处理	排序	较难	17.84%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_025
{
    // #include <iostream>
    // #include <vector>
    // #include <map>
    // #include <algorithm>
    // using namespace std;

    bool isInclude(int n, int m)
    {
        string sn = to_string(n);
        string sm = to_string(m);
        if (sm.find(sn) != std::string::npos)
        {
            return true;
        }
        return false;
    }

    bool findRInI(int n, const vector<int> &v, vector<int> &w)
    {
        bool ret = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (isInclude(n, v[i]))
            {
                w.push_back(i);
                w.push_back(v[i]);
                ret = true;
            }
        }
        return ret;
    }

    int solution1(void)
    {
        int n = 0, m = 0;
        while (cin >> n)
        {
            vector<int> I(n, 0);
            for (auto &i : I)
            {
                cin >> i;
            }
            cin >> m;
            vector<int> R(m, 0);
            for (auto &i : R) cin >> i;
            sort(R.begin(), R.end());
            map<int, int> mRInfo;
            vector<int> vIInfo; // 2 * n vector
            for (int i = 0; i < R.size(); i++)
            {
                int count = vIInfo.size() / 2;
                if (mRInfo.find(R[i]) != mRInfo.end()) continue;
                if (findRInI(R[i], I, vIInfo))
                {
                    count = vIInfo.size() / 2 - count;
                    mRInfo.insert(make_pair(R[i], count));
                }
            }
            cout << mRInfo.size() * 2 + vIInfo.size();
            int startPos = 0;
            for (map<int, int>::iterator iter = mRInfo.begin(); iter != mRInfo.end(); iter++)
            {
                cout << ' ' << iter->first << ' ' << iter->second;
                for (int i = startPos; i < startPos + iter->second * 2; i++)
                {
                    cout << ' ' << vIInfo[i];
                }
                startPos = startPos + iter->second * 2;
            }
            cout << endl;
        }
        return 0;
    }
}

// HJ26	字符串排序	排序字符串	中等	29.55%
// 难度：**，技巧：**
namespace NiuKeHuaWeiTraining_026
{
    int solution1(void)
    {
        string str = "";
        while (getline(cin, str))
        {
            string arr[26] = {""};  // 先按大小写字母顺序保存字母
            for (unsigned int i = 0; i < str.size(); i++)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                {
                    arr[str[i] - 'a'] += str[i];
                }
                else if (str[i] >= 'A' && str[i] <= 'Z')
                {
                    arr[str[i] - 'A'] += str[i];
                }
            }

            int j = 0, k = 0;
            for (unsigned int i = 0; i < str.size(); i++)
            {
                if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                {
                    while (1) // 想办法把大小写字母塞回去
                    {
                        if (arr[j].size() > 0 && arr[j].size() > k)
                        {
                            str[i] = char(arr[j][k]);
                            k++;
                            break;
                        }
                        else
                        {
                            j++;
                            k = 0;
                        }
                    }
                }
            }

            cout << str << endl;
            str.clear();
        }

        return 0;
    }
}

// HJ27	查找兄弟单词		困难	15.67%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_027
{
    bool isBrother(string s1, string s2)
    {
        // 可用如下三行解决
        // sort(s1.begin(), s2.end());
        // sort(s2.begin(), s2.end());
        // return s1 == s2;

        bool ret = true;
        
        if (s1.size() != s2.size() || s1 == s2)
        {
            ret = false;
        }
        else
        {
            int arr1[26] = {0}, arr2[26] = {0};
            for (int i = 0; i < s1.size(); i++)
            {
                arr1[s1[i] - 'a']++;
                arr2[s2[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (arr1[i] != arr2[i])
                {
                    ret = false;
                    break;
                }
            }
        }
        
        return ret;
    }

    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            vector<string> str(n);
            for (auto &i : str)
            {
                cin >> i;
            }
            string s;
            cin >> s;
            int index = 0;
            cin >> index;
            sort(str.begin(), str.end());
            
            vector<string> out;
            for (int i = 0; i < n; i++)
            {
                if (isBrother(str[i], s))
                {
                    out.push_back(str[i]);
                }
            }

            if (index < out.size())
            {
                cout << out.size() << endl << out[index - 1] << endl;
            }
            else
            {
                cout << out.size() << endl;
            }
        }
        return 0;
    }
}

// HJ28	素数伴侣	排序	困难	22.79%
// 难度：****，技巧：****， fail。二分图。。。
// namespace NiuKeHuaWeiTraining_028
// {
//     int solution1(void)
//     {
//         vector<int> v;
//         v.erase();
//         return 0;
//     }
// }

// HJ29	字符串加解密	字符串	较难	22.59%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_029
{
    int solution1(void)
    {
        string strToEncrypted;
        while (getline(cin, strToEncrypted))
        {
            for (int i = 0; i < strToEncrypted.size(); i++)
            {
                if (strToEncrypted[i] >= 'a' && strToEncrypted[i] < 'z')
                {
                    strToEncrypted[i] = strToEncrypted[i] - 'a' + 'A' + 1;
                }
                else if (strToEncrypted[i] >= 'A' && strToEncrypted[i] < 'Z')
                {
                    strToEncrypted[i] = strToEncrypted[i] - 'A' + 'a' + 1;
                }
                else if (strToEncrypted[i] == 'z')
                {
                    strToEncrypted[i] = 'A';
                }
                else if (strToEncrypted[i] == 'Z')
                {
                    strToEncrypted[i] = 'a';
                }
                else if (strToEncrypted[i] >= '0' && strToEncrypted[i] < '9')
                {
                    strToEncrypted[i] += 1;
                }
                else if (strToEncrypted[i] == '9')
                {
                    strToEncrypted[i] = '0';
                }
            }
            cout << strToEncrypted << endl;
            string strToDecrypted;
            getline(cin, strToDecrypted);
            for (int i = 0; i < strToDecrypted.size(); i++)
            {
                if (strToDecrypted[i] > 'a' && strToDecrypted[i] <= 'z')
                {
                    strToDecrypted[i] = strToDecrypted[i] - 'a' + 'A' - 1;
                }
                else if (strToDecrypted[i] > 'A' && strToDecrypted[i] <= 'Z')
                {
                    strToDecrypted[i] = strToDecrypted[i] - 'A' + 'a' - 1;
                }
                else if (strToDecrypted[i] == 'a')
                {
                    strToDecrypted[i] = 'Z';
                }
                else if (strToDecrypted[i] == 'A')
                {
                    strToDecrypted[i] = 'z';
                }
                else if (strToDecrypted[i] > '0' && strToDecrypted[i] <= '9')
                {
                    strToDecrypted[i] -= 1;
                }
                else if (strToDecrypted[i] == '0')
                {
                    strToDecrypted[i] = '9';
                }
            }
            cout << strToDecrypted << endl;
        }
        return 0;
    }
}

// HJ30	字符串合并处理	字符串排序	较难	22.83%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_030
{
    string sortStr(string &s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] > s[j])
                {
                    swap(s[i], s[j]);
                }
            }
        }
        return s;
    }

    string reverseBit(string &s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            int d = -1; // 这里不要=0，是个坑。。。
            if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9'))
            {
                if (c >= 'a' && c <= 'f')
                {
                    d = 0xA + c - 'a';
                }
                else if (c >= 'A' && c <= 'F')
                {
                    d = 0xA + c - 'A';
                }
                else
                {
                    d = c - '0';
                }
                
                d = ((d & 8) >> 3 ) | ((d & 4) >> 1) | ((d & 2) << 1) | ((d & 1) << 3);
            }
            
            if (d >= 0xA && d <= 0xF)
            {
                c = d - 0xA + 'A';
                s[i] = char(c);
            }
            else if (d >= 0 && d <= 9)
            {
                c = d + '0';
                s[i] = char(c);
            }
        }
        return s;
    }

    int solution1(void)
    {
        string str1, str2;
        while (cin >> str1 >> str2)
        {
            string str = str1 + str2;
            str1.clear();
            str2.clear();
            for (int i = 0; i < str.size(); i++)
            {
                if (i % 2)
                {
                    str2 += str[i];
                }
                else
                {
                    str1 += str[i];
                }
            }

            sortStr(str1);
            sortStr(str2);
            reverseBit(str1);
            reverseBit(str2);
            str.clear();
            int len = (str1.size() <= str2.size() ? str1.size() : str2.size());
            
            for (int i = 0; i < len; i++)
            {
                str += str1[i];
                str += str2[i];
            }
            if (str1.size() < str2.size())
            {
                str += str2[str2.size() - 1]; // 注意：这里不能用 str2[-1]！！
            }
            else if (str1.size() > str2.size())
            {
                str += str1[str1.size() - 1];
            }

            cout << str << endl;
        }
        return 0;
    }
}

// HJ31	【中级】单词倒排	字符串排序	困难	16.42%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_031
{
    int solution1(void) // solution 2 更切题，但是这个solution1通用性稍微强一点。
    {
        string str;
        while (getline(cin, str))
        {
            string str1, output;
            vector<string> words;
            vector<char> symbols;
            
            int i = 0, j = str.size() - 1;
            for (; i < str.size(); i++)
            {
                if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                {
                    str1 += str[i];
                    if (i == str.size() - 1)
                    {
                        words.push_back(str1);
                        str1.clear();
                    }
                }
                else
                {
                    words.push_back(str1);
                    symbols.push_back(' ');
                    str1.clear();
                }
            }
            
            int len = (words.size() > symbols.size() ? symbols.size() : words.size());
            i = 0;
            for (; i < len; i++)
            {
                output += (words[words.size() - 1 - i] + (symbols[i]));
            }
            if (words.size() > symbols.size())
            {
                output += words[0];
            }
            else if (words.size() < symbols.size())
            {
                output += (symbols[symbols.size() - 1]);
            }
            
            while (output[0] == ' ')
            {
                output = output.substr(1);
            }
            
            while (output[output.size() - 1] == ' ')
            {
                output = output.substr(0, output.size() - 2);
            }
            
            cout << output << endl;
        }
        return 0;
    }

    int solution2(void)
    {
        string str;
        while (getline(cin, str))
        {
            string str1, output;
            vector<string> words;

            for (int i = 0; i < str.size(); i++)
            {
                if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                {
                    str1 += str[i];
                    if (i == str.size() - 1)
                    {
                        words.push_back(str1);
                        str1.clear();
                    }
                }
                else if (str1.size())
                {
                    words.push_back(str1);
                    str1.clear();
                }
            }
            
            output += words[words.size() - 1];
            for (int i = 1; i < words.size(); i++)
            {
                output += (" " + words[words.size() - 1 - i]); // 为了切题以及更简单化，强制使用空格作为分隔符。
            }
            
            cout << output << endl;
        }
        return 0;
    }
}

// HJ32	【中级】字符串运用-密码截取	字符串	较难	24.00%
// 难度：*，技巧：*。
// solution1 有1/102没通过，怀疑是用例问题，但是无法获取用例。
// solution2 AC, 第二次做就pass，换了一种方法
namespace NiuKeHuaWeiTraining_032
{
    int solution1(void)
    {
        string pwd;
        while (getline(cin, pwd))
        {
            int max_len = 0;
            for (int i = 0; i < pwd.size(); i++)
            {
                if (i > 0 && pwd[i - 1] == pwd[i + 1])
                {
                    for (int j = 1; j < pwd.size(), i >= j; j++)
                    {
                        if (pwd[i - j] == pwd[i + j])
                        {
                            int len = j * 2 + 1;
                            max_len = (max_len < len ? len : max_len);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if (pwd[i] == pwd[i + 1])
                {
                    for (int j = 1; j < pwd.size(), i >= j - 1; j++)
                    {
                        if (pwd[i - j + 1] == pwd[i + j])
                        {
                            int len = j * 2;
                            max_len = (max_len < len ? len : max_len);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            cout << max_len << endl;
        }
        return 0;
    }

    int solution2(void)
    {
        string str;
        while (cin >> str)
        {
            int length = 0;
            for (int i = 0; i < str.size() - 1; i++)
            {
                for (int j = str.size() - 1; j > i; j--)
                {
                    if (str[i] == str[j])
                    {
                        bool match = true;
                        for (int k = 1; i + k <= j - k; k++)
                        {
                            if (str[i + k] != str[j - k])
                            {
                                match = false;
                                break;
                            }
                        }
                        if (match)
                        {
                            length = (length > (j - i + 1) ? length : (j - i + 1));
                        }
                    }
                }
            }
            cout << length << endl;
        }
        return 0;
    }
}

// HJ33	整数与IP地址间的转换	字符串	较难	25.29%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_033
{
    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            int n = 0;
            n = stoi(str.substr(0, str.find('.')));
            str = str.substr(str.find('.') + 1);
            unsigned int m = 0;
            m = m | (n << 24);
            n = stoi(str.substr(0, str.find('.')));
            str = str.substr(str.find('.') + 1);
            m = m | (n << 16);
            n = stoi(str.substr(0, str.find('.')));
            str = str.substr(str.find('.') + 1);
            m = m | (n << 8);
            n = stoi(str);
            m = m | n;
            cout << m << endl;
            
            string p;
            getline(cin, p);
            unsigned int i = 0;
            while (p.size())
            {
                i = i * 10 + (p[0] - '0');
                p = p.substr(1);
            }
    //         i = stoi(p); // Error: 运行错误:请检查是否存在数组、列表等越界非法访问，内存非法访问等情况. terminate called after throwing an instance of 'std::out_of_range'. what(): stoi
            string ip;
            ip = to_string((i >> 24) & 0xFF) + "." + to_string((i >> 16) & 0xFF) + "." + to_string((i >> 8) & 0xFF) + "." + to_string(i & 0xFF);
            cout << ip << endl;
        }
        return 0;
    }
}

// HJ34	图片整理	字符串	中等	37.59%
// 难度：*，技巧：*， 仅限C语言
namespace NiuKeHuaWeiTraining_034
{
    #include <stdlib.h>
    #include <stdio.h>
    int solution1(void) // 提交显示超时，不知道什么原因
    {
        char *pic;
        pic = (char *)malloc(1024);
        while (scanf("%s", pic))
        {
            int len = 0;
            int i = 0;
            while (pic[i++])
            {
                len++;
            }

            for (unsigned int i = 0; i < len; i++)
            {
                for (unsigned int j = i + 1; j < len; j++)
                {
                    if (pic[i] > pic[j])
                    {
                        char temp = pic[j];
                        pic[j] = pic[i];
                        pic[i] = temp;
                    }
                }
            }

            printf("%s\n", pic);
            
            memset(pic, 0, 1024);
        }
        
        free(pic);

        return 0;
    }

    int solution2(void) // C++
    {
        string pic;
        while (cin >> pic)
        {
            unsigned int len = 0;
            int i = 0;
            while (pic[i++])
            {
                len++;
            }

            for (unsigned int i = 0; i < len; i++)
            {
                for (unsigned int j = i + 1; j < len; j++)
                {
                    if (pic[i] > pic[j])
                    {
                        char temp = pic[j];
                        pic[j] = pic[i];
                        pic[i] = temp;
                    }
                }
            }

            cout << pic << endl;;
            
            pic = "";
        }

        return 0;
    }
}

// HJ35	蛇形矩阵	数组	中等	34.29%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_035
{
    int solution1(void)
    {
        int n;
        while (cin >> n)
        {
            int count = 0;
            int t = 1;
            for (int i = 0; i < n; i++)
            {
                t = t + i;
                int s = t;
                for (int j = 0; j < n - i; j++)
                {
                    s = ( j == 0 ? s : s + j + i + 1);
                    cout << s << " ";
                }
                cout << endl;
            }
            // 反过来了。。
            // for (int i = 0; i < n; i++)
            // {
            //     t = t + i;
            //     int s = t;
            //     for (int j = 0; j < n - i; j++)
            //     {
            //         s = s + j + i;
            //         cout << s << " ";
            //     }
            //     cout << endl;
            // }
        }
        return 0;
    }
}

// HJ36	字符串加密	字符串	中等	33.56%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_036
{
    int solution1(void)
    {
        string key;
        while (getline(cin, key))
        {
            string strToBeEncrypted;
            getline(cin, strToBeEncrypted);
            map<char, char> mStr;
            int i = 0;
            while (i < key.size())
            {
                if (key[i] >= 'a' && key[i] <= 'z')
                {
                    key[i] = key[i] - 'a' + 'A';
                }
                i++;
            }

            i = 0;
            int j = i;
            while (i < key.size() && j < key.size())
            {
                // Remove duplicate
                if (key.substr(0, j).find(key[j]) != std::string::npos)
                {
                    j++;
                    continue;
                }
                else
                {
                    mStr.insert(make_pair<char, char>(char('A' + i), char(key[j])));
                    i++;
                    j++;
                }
            }

            // Fill in the rest element
            string bak = key;
            for (; i < 26; i++)
            {
                int j = 0;
                while (j < 26)
                {
                    if (bak.find(('A' + j)) == std::string::npos)
                    {
                        mStr.insert(make_pair<char, char>(char('A' + i), char('A' + j)));
                        bak += ('A' + j);
                        break;
                    }
                    j++;
                }
            }

            for (int i = 0; i < strToBeEncrypted.size(); i++)
            {
                if (strToBeEncrypted[i] >= 'A' && strToBeEncrypted[i] <= 'Z')
                {
                    strToBeEncrypted[i] = mStr[strToBeEncrypted[i]];
                }
                else if(strToBeEncrypted[i] >= 'a' && strToBeEncrypted[i] <= 'z')
                {
                    strToBeEncrypted[i] = char(mStr[char(strToBeEncrypted[i] - 'a' + 'A')] - 'A' + 'a');
                }
            }

            cout << strToBeEncrypted << endl;
        }
        return 0;
    }

    #include <cctype>
    #include <algorithm>
    int solution2(void)
    {
        string key;
        while (getline(cin, key))
        {
            string strToBeEncrypted;
            getline(cin, strToBeEncrypted);
            char c[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            // to upper
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            // while (i < key.size())
            // {
            //     if (key[i] >= 'a' && key[i] <= 'z')
            //     {
            //         key[i] = key[i] - 'a' + 'A';
            //     }
            //     i++;
            // }

            // remove duplicate
            int i = 0;
            while (i < key.size())
            {
                if (key.substr(0, i).find(key[i]) != std::string::npos)
                {
                    key = key.substr(0, i) + key.substr(i + 1);
                    continue;
                }
                else
                {
                    i++;
                }
            }

            i = 0;
            while (i < key.size())
            {
                c[i] = char(key[i]);
                i++;
            }

            // Fill in the rest element
            string bak = key;
            for (; i < 26; i++)
            {
                int j = 0;
                while (j < 26)
                {
                    if (bak.find(('A' + j)) == std::string::npos)
                    {
                        // mStr.insert(make_pair<char, char>(char('A' + i), char('A' + j)));
                        c[i] = char('A' + j);
                        bak += ('A' + j);
                        break;
                    }
                    j++;
                }
            }

            for (int i = 0; i < strToBeEncrypted.size(); i++)
            {
                if (strToBeEncrypted[i] >= 'A' && strToBeEncrypted[i] <= 'Z')
                {
                    strToBeEncrypted[i] = c[strToBeEncrypted[i] - 'A'];
                }
                else if(strToBeEncrypted[i] >= 'a' && strToBeEncrypted[i] <= 'z')
                {
                    strToBeEncrypted[i] = c[strToBeEncrypted[i] - 'a'] - 'A' + 'a';
                }
            }

            cout << strToBeEncrypted << endl;
        }
        return 0;
    }
}

// HJ37	统计每个月兔子的总数	排序	简单	34.71%
// 难度：**，技巧：***
namespace NiuKeHuaWeiTraining_037
{
    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            // 寿命为一个月的兔子数是m_1个，两个月大的兔子数是m_2个，三个月大的兔子数是m_3个。
            int m_1 = 1, m_2 = 0, m_3 = 0;

            while (--n)
            {
                m_3 = m_2 + m_3;
                m_2 = m_1;
                m_1 = m_3;
            }

            cout << m_1 + m_2 + m_3 << endl;
        }
        return 0;
    }

    int solution2(void)
    {
        int n = 0;
        while (cin >> n)
        {
            // cur为本月兔子总数。
            // prev本月兔子总数， cur+prev是下个月兔子总数
            // 成斐波那契数列规则， 1 1 2 3 5 8 13 21 34 55 89 144
            int prev = 0, cur = 1;

            while (n--)
            {
                int t = cur;
                cur = cur + prev;
                prev = t;
            }

            cout << prev << endl;
        }
        return 0;
    }
}

// HJ38	求小球落地5次后所经历的路程和第5次反弹的高度	模拟	中等	27.56%
// 难度：*，技巧：*, 一次过，pass
namespace NiuKeHuaWeiTraining_038
{
    void getHeight(float n, float &sum, float &lastH, int times)
    {
    //     sum = n + 2 * n / 2 + 2 * n / 4 + 2 * n / 8 + 2 * n / 16; // 等比数列求和
        sum = n + 2 * n * (1 - 1 / pow(2, times - 1));
    //     lastH = n / 32;
        lastH = n * (1 / pow(2, times)); // 等比数列求第 n 项
    }

    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            float sum = 0, lastH = 0;
            getHeight(float(n), sum, lastH, 5);
            cout << sum << endl << lastH << endl;
        }
        return 0;
    }
}

// HJ39	判断两个IP是否属于同一子网	字符串模拟	较难	12.94%
// 难度：*，技巧：*, 通过率 7/10
namespace NiuKeHuaWeiTraining_039
{
    struct IP
    {
        unsigned int firstNumber;
        unsigned int secondNumber;
        unsigned int thirdNumber;
        unsigned int lastNumber;
    };

    bool getAddress(string s, IP &ip)
    {
        ip = {0};
        unsigned int n = 0;
        int count = 0;
        while (s.size())
        {
            if (s[0] >= '0' && s[0] <= '9')
            {
                n = 10 * n + s[0] - '0';
                if (n > 255)
                {
                    return false;
                }
            }
            else if (s[0] == '.')
            {
                switch (count)
                {
                    case 0:
                        ip.firstNumber = n;
                        n = 0;
                        break;
                    case 1:
                        ip.secondNumber = n;
                        n = 0;
                        break;
                    case 2:
                        ip.thirdNumber = n;
                        n = 0;
                        break;
                }
                count++;
            }
            else if (s.size() == 1)
            {
                ip.lastNumber = n;
            }
            else
            {
                return false;
            }
            s = s.substr(1);
        }
        if (count == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
        return false;
    }

    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            IP mask;
            bool illegel = false;
            if (getAddress(str, mask) == false)
            {
                illegel = true;
            }
            
            string ip1, ip2;
            getline(cin, ip1);
            getline(cin, ip2);
            IP vIP1;
            IP vIP2;
            if (getAddress(ip1, vIP1) == false || getAddress(ip2, vIP2) == false)
            {
                illegel = true;
            }

            bool match = false;

            vIP1.firstNumber &= mask.firstNumber;
            vIP2.firstNumber &= mask.firstNumber;
            vIP1.secondNumber &= mask.secondNumber;
            vIP2.secondNumber &= mask.secondNumber;
            vIP1.thirdNumber &= mask.thirdNumber;
            vIP2.thirdNumber &= mask.thirdNumber;
            vIP1.lastNumber &= mask.lastNumber;
            vIP2.lastNumber &= mask.lastNumber;
            if (vIP1.firstNumber == vIP2.firstNumber && vIP1.secondNumber == vIP2.secondNumber && 
                    vIP1.thirdNumber == vIP2.thirdNumber && vIP1.lastNumber == vIP2.lastNumber)
            {
                match = true;
            }

            cout << (illegel ? 1 : (match ? 0 : 2)) << endl;
        }
        return 0;
    }
}

// HJ40	输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数	字符串	中等	34.93%
// 难度：*，技巧：*, AC, 一次过
namespace NiuKeHuaWeiTraining_040
{
    int solution1(void)
    {
        string str;
        while(getline(cin, str))
        {
            // arr[0] is alphabet count, arr[1] is blank count,
            // arr[2] is number count, arr[3] is others count, 
            int arr[4] = {0};
            for (int i = 0; i < str.size(); i++)
            {
                if ((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z'))
                {
                    arr[0]++;
                }
                else if (str[i] == ' ')
                {
                    arr[1]++;
                }
                else if (str[i] >= '0' && str[i] <= '9')
                {
                    arr[2]++;
                }
                else
                {
                    arr[3]++;
                }
            }
            
            for (int i = 0; i < 4; i++)
            {
                cout << arr[i] << endl;
            }
        }
        return 0;
    }
}

// HJ41	称砝码	字符串	较难	33.53%
// 难度：*，技巧：***，找规律，第一遍没过，第二遍参考教程，pass。
// solution2种使用set可以自动去掉重复值
namespace NiuKeHuaWeiTraining_041
{
    int solution1(void)
    {
        int n;
        while (cin >> n)
        {
            int m[10] = {0};
            int x[10] = {0};
            int i = 10;
            for (i = 0; i < n; i++)
            {
                cin >> m[i];
            }
            
            for (i = 0; i < n; i++)
            {
                cin >> x[i];
            }
            
            vector<int> v;
            for (int i = 0; i <= x[0]; i++)
            {
                v.push_back(m[0] * i);
            }
            
            for (int i = 1; i < n; i++) // 遍历砝码编号
            {
                int s = v.size(); // 保存当前v的大小
                for (int j = 0; j <= x[i]; j++) // 遍历当前砝码的数量
                {
                    for (int k = 0; k < s; k++) // 遍历前一个砝码编号的重量数
                    {
                        if (find(v.begin(), v.end(), v[k] + m[i] * j) == v.end())
                        {
                            v.push_back(v[k] + m[i] * j);
                        }
                    }
                }
            }
            
            cout << v.size() << endl;
        }
        return 0;
    }

    int solution2(void) // 用set自动删掉重复值
    {
        int n;
        while (cin >> n)
        {
            int m[10] = {0};
            int x[10] = {0};
            int i = 10;
            for (i = 0; i < n; i++)
            {
                cin >> m[i];
            }
            
            for (i = 0; i < n; i++)
            {
                cin >> x[i];
            }
            
            set<int> s;
            for (int i = 0; i <= x[0]; i++)
            {
                s.insert(m[0] * i);
            }
            
            for (int i = 1; i < n; i++) // 遍历砝码编号
            {
                set<int> tmp(s);
                for (int j = 1; j <= x[i]; j++) // 遍历当前砝码的数量, j 为0时，肯定重复了，因此从1开始
                {
                    for (set<int>::iterator it = tmp.begin(); it != tmp.end(); it++) // 遍历前一个砝码编号的重量数
                    {
                        s.insert(*it + m[i] * j); // set 自动删掉重复值
                    }
                }
            }
            
            cout << s.size() << endl;
        }
        return 0;
    }
}

// HJ42	学英语	字符串	较难	26.47%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_042
{
// #include <iostream>
// using namespace std;

    string getStr(int n)
    {
        string str;
        switch (n)
        {
            case 0:
                str.clear();
                break;
            case 1:
                str = "one";
                break;
            case 2:
                str = "two";
                break;
            case 3:
                str = "three";
                break;
            case 4:
                str = "four";
                break;
            case 5:
                str = "five";
                break;
            case 6:
                str = "six";
                break;
            case 7:
                str = "seven";
                break;
            case 8:
                str = "eight";
                break;
            case 9:
                str = "nine";
                break;
            default:
                str = "error";
                break;
        }
        return str;
    }

    string getTwoDigitStr(int n)
    {
        string str;
        if (n < 10)
        {
            str = getStr(n);
            return str;
        }
        else if (n < 20)
        {
            switch (n)
            {
                case 10:
                    str = "ten";
                    break;
                case 11:
                    str = "eleven";
                    break;
                case 12:
                    str = "twelve";
                    break;
                case 13:
                    str = "thirteen";
                    break;
                case 14:
                    str = "fourteen";
                    break;
                case 15:
                    str = "fifteen";
                    break;
                case 16:
                    str = "sixteen";
                    break;
                case 17:
                    str = "seventeen";
                    break;
                case 18:
                    str = "eighteen";
                    break;
                case 19:
                    str = "nineteen";
                    break;
                default:
                    str = "error";
                    break;
            }
        }
        else if (n >= 20 && n < 100)
        {
            int tenthPart = n / 10;
            int lastPart = n % 10;
            switch (tenthPart)
            {
                case 2:
                    str = "twenty";
                    break;
                case 3:
                    str = "thirty";
                    break;
                case 4:
                    str = "forty";
                    break;
                case 5:
                    str = "fifty";
                    break;
                case 6:
                    str = "sixty";
                    break;
                case 7:
                    str = "seventy";
                    break;
                case 8:
                    str = "eighty";
                    break;
                case 9:
                    str = "ninety";
                    break;
                default:
                    str = "error";
                    break;
            }

            str += (' ' + getStr(lastPart));
        }
        else
        {
            str = "error";
        }
        return str;
    }

    string getThreeDigitStr(int n)
    {
        string str;
        if (n / 100)
        {
            str += (getStr(n / 100) + " hundred");
            n = n % 100;
            str += " and ";
        }
        if (n > 0)
        {
            str += getTwoDigitStr(n);
        }
        return str;
    }

    int solution1(void)
    {
        long n;
        while (cin >> n)
        {
            string output;
            int temp = 0;
            if (n > 0)
            {
                if (n >= 10000000000)
                {
                    output = "error";
                }
                else
                {
                    if (n / 1000000000)
                    {
                        temp = n / 1000000000;
                        output += (getStr(temp) + " billion ");
                        n = n % 1000000000;
                    }
                    if (n / 1000000)
                    {
                        temp = n / 1000000;
                        output += (getThreeDigitStr(temp) + " million ");
                        n = n % 1000000;
                    }
                    if (n / 1000)
                    {
                        temp = n / 1000;
                        output += (getThreeDigitStr(temp) + " thousand ");
                        n = n % 1000;
                    }
                    if (n > 0)
                    {
                        temp = n;
                        output += (getThreeDigitStr(temp));
                    }
                }
            }
            else
            {
                output = "zero";
            }

            if (output.find("error") != std::string::npos)
            {
                output = "error ";
            }
            
            for (int i = 1; i < output.size(); i++)
            {
                if (output[i - 1] == ' ' && output[i] == ' ')
                {
                    output = output.substr(0, i) + output.substr(i + 1);
                    i--;
                }
            }
            if (output[0] == ' ')
            {
                output = output.substr(1);
            }
            if (output.substr(0, 4) == "and ")
            {
                output = output.substr(4);
            }
            cout << output << endl;
        }
        return 0;
    }
}

// HJ43	迷宫问题	排序	中等	29.66%
// 难度：***，技巧：***, 参考讨论信息。pass
namespace NiuKeHuaWeiTraining_043
{
    int N = 0, M = 0;

    vector<vector<int>> path_tmp;
    vector<vector<int>> path_best;

    bool checkValid(int x, int y)
    {
        return ((x < N) && (y < M) && (x >= 0) && (y >= 0));
    }

    void findPath(int x, int y, vector<vector<int>> &arr) // 关键是回溯算法和条件。
    {
        arr[x][y] = 1; // set flag，置1很巧妙。
        path_tmp.push_back({x, y});
        if ((x + 1) == N && (y + 1) == M && (path_tmp.size() < path_best.size() || path_best.empty()))
        {
            path_best = path_tmp;
        }
        if (checkValid(x + 1, y) && arr[x + 1][y] == 0)
        {
            findPath(x + 1, y, arr);
        }
        if (checkValid(x, y + 1) && arr[x][y + 1] == 0)
        {
            findPath(x, y + 1, arr);
        }
        if (checkValid(x - 1, y) && arr[x - 1][y] == 0)
        {
            findPath(x - 1, y, arr);
        }
        if (checkValid(x, y - 1) && arr[x][y - 1] == 0)
        {
            findPath(x, y - 1, arr);
        }
        
        arr[x][y] = 0; // reset flag
        path_tmp.pop_back(); // 回退
    }

    int solution1(void)
    {
        while (cin >> N >> M)
        {
            vector<vector<int>> arr(N, vector<int>(M));
            path_tmp.clear();
            path_best.clear();
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    cin >> arr[i][j];
                }
            }
            findPath(0, 0, arr);
            
            for (auto &i : path_best)
            {
                cout << '(' << i[0] << ',' << i[1] << ')' << endl;
            }
        }
        return 0;
    }
}

// HJ44	Sudoku-Java	搜索数学	困难	21.39%
// 难度：**，技巧：***, 自己做fail，下面参考了别人的答案，可以pass
namespace NiuKeHuaWeiTraining_044
{
    bool checkNumber(int arr[9][9], int n, int pos)
    {
        bool ret = true;
        int row = pos / 9;
        int col = pos % 9;
        
        // 检查本行是否有重复
        for (int j = 0; j < 9; j++)
        {
            if (arr[row][j] == n)
            {
                ret = false;
                return ret;
            }
        }
        
        // 检查本列是否有重复
        for (int i = 0; i < 9; i++)
        {
            if (arr[i][col] == n)
            {
                ret = false;
                return ret;
            }
        }
        
        // 检查小九宫格是否有重复
        for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
        {
            for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
            {
                if (arr[i][j] == n)
                {
                    ret = false;
                    return ret;
                }
            }
        }
        
        return ret;
    }

    bool DFS(int n, int arr[9][9])
    {
        if (n == 81)
        {
            return true;
        }
        else if (arr[n / 9][n % 9] != 0)
        {
            return DFS(n + 1, arr);
        }
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (checkNumber(arr, i, n)) // 即使当前满足条件，也要考虑后面是否有冲突。如果后面的待填项有冲突，就需要从这里重新推算。
                {
                    arr[n / 9][n % 9] = i;
                    if (DFS(n + 1, arr))
                    {
                        return true;
                    }
                    else
                    {
                        arr[n / 9][n % 9] = 0;
                    }
                }
            }
        }
        return false;
    }

    int solution1(void)
    {
        int array[9][9] = {0};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> array[i][j];
            }
        }
        
        DFS(0, array);
        
        for (int i = 0; i < 9; i++)
        {
            cout << array[i][0];
            for (int j = 1; j < 9; j++)
            {
                cout << ' ' << array[i][j];
            }
            cout << endl;
        }
        
        return 0;
    }
}

// HJ45	名字的漂亮度	字符串	中等	29.21%
// 难度：*，技巧：*, AC, 一次过
namespace NiuKeHuaWeiTraining_045
{
    int solution1(void)
    {
        int n;
        string str;
        while (cin >> n)
        {
            while (n-- > 0)
            {
                str.clear();
                cin >> str;
                int arr[26] = {0};
                int beautifulCount = 0;
                for (int i = 0; i < str.size(); i++)
                {
                    if (str[i] >= 'a' && str[i] <= 'z')
                    {
                        arr[str[i] - 'a']++;
                    }
                    else if (str[i] >= 'A' && str[i] <= 'Z')
                    {
                        arr[(str[i] - 'A' + 'a')]++;
                    }
                }

                // sort
                for (int i = 0; i < 26; i++)
                {
                    for (int j = i; j < 26; j++)
                    {
                        if (arr[i] < arr[j])
                        {
                            swap(arr[i], arr[j]);
                        }
                    }
                    beautifulCount += arr[i] * (26 - i);
                }

                cout << beautifulCount << endl;
            }
        }
        return 0;
    }
}

// HJ46	按字节截取字符串	字符串	中等	36.87%
// 难度：*，技巧：*, AC, 逻辑一次过，cin和getline没统一浪费了一次。
namespace NiuKeHuaWeiTraining_046
{
    int solution1(void)
    {
        string str;
        while (cin >> str) // 注意 cin >> str的形式要统一，不要上面用cin下面就用getline，这样会冲突
        {
            int n;
            cin >> n;
            
            cout << str.substr(0, n) << endl;
        }
        return 0;
    }
}

// HJ47	线性插值	数组	较难	28.77%
// 难度：*，技巧：*，题目有点难以理解，实际上参数n可以不需要。。结合讨论组的信息，pass
namespace NiuKeHuaWeiTraining_047
{
    int solution1(void)
    {
        int m = 0, n = 0;
        while (cin >> m >> n)
        {
    //         map<int, int> md;
            int M = 0, A = 0, N = 0, B = 0;
            cin >> M >> A;
    //         md.insert(make_pair(M, A));
            cout << M << " " << A << endl;
            for (int i = 1; i < m; i++)
            {
                cin >> N >> B;
                if (M == N) continue;
                else
                {
                    for (int j = 1; j < N - M; j++)
                    {
                        int tmp = A + (B - A) / (N - M) * j;
    //                     md.insert(make_pair(M + j, tmp)); // 注意： map会自动排序，这里不适合。
                        cout << M + j << ' ' << tmp << endl;
                    }
                    cout << N << ' ' << B << endl;
                    M = N;
                    A = B;
                }
            }
    //         md.insert(make_pair(N, B));
            
    //         for (map<int, int>::iterator it = md.begin(); it != md.end(); it++)
    //         {
    //             cout << it->first << ' ' << it->second << endl;
    //         }
        }
        return 0;
    }
}

// HJ48	从单向链表中删除指定值的节点	链表	中等	28.30%
// namespace NiuKeHuaWeiTraining_048
// {
//     int solution1(void)
//     {
//         return 0;
//     }
// }

// HJ49	多线程	字符串链表栈队列	中等	34.54%
// 难度：*，技巧：*, AC, 一次过
namespace NiuKeHuaWeiTraining_049
{
    void printA()
    {
        cout << 'A';
    }
    void printB()
    {
        cout << 'B';
    }
    void printC()
    {
        cout << 'C';
    }
    void printD()
    {
        cout << 'D';
    }
    int solution1(void)
    {
        int n;
        while (cin >> n)
        {
            while (n--)
            {
                printA();
                printB();
                printC();
                printD();
            }
            cout << endl;
        }
        return 0;
    }
}

// HJ50	四则运算	字符串栈数学	简单	48.59%
// 难度：****，技巧：****
// namespace NiuKeHuaWeiTraining_050
// {
//     int solution1(void)
//     {
//         string str;
//         cin >> str;

//         int i = 0;
//         while(str[i])
//         {
//             if (str[i] == "{")
//             {

//             }
//             else if (str[i] >= '0' && str[i] <= '9')
//             {

//             }
//         }

//         return 0;
//     }
// }

// HJ51	输出单向链表中倒数第k个结点	链表	较难	21.08%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_051
{
    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            vector<int> v(n);
            for (auto &i : v)
            {
                cin >> i;
            }
            int m = 0;
            cin >> m;
            int count = 0;
            for (vector<int>::iterator iter = v.end() - 1; iter >= v.begin(); iter--)
            {
                count++;
                if (count == m)
                {
                    cout << *iter << endl;
                    break;
                }
            }
            if (count == v.size())    cout << 0 << endl;
        }
        return 0;
    }
}

// HJ52	计算字符串的距离	字符串	中等	32.73%
// 难度：***，技巧：***
// namespace NiuKeHuaWeiTraining_052
// {
//     int solution1(void)
//     {
//         return 0;
//     }
// }

// HJ53	iNOC产品部-杨辉三角的变形	字符串	简单	41.16%
// 难度：*，技巧：***
namespace NiuKeHuaWeiTraining_053
{
    // int getValue(int n, int i)
    // {
    //     if (n <= 2 || i == 1)
    //     {
    //         return 1;
    //     }
    //     else if(i == 2)
    //     {
    //         return getValue(n - 1, i - 1) + getValue(n - 1, i);
    //     }
    //     else if (i >= n - 1)
    //     {
    //         // 每一行都是以第n个数为中心对称，因此，当i > n-1 时，取第n-1-(i-(n-1))个值。
    //         return getValue(n - 1, i - 2) + getValue(n - 1, i - 1) + getValue(n - 1, 2 * n - 2 - i);
    //     }
    //     return getValue(n - 1, i - 2) + getValue(n - 1, i - 1) + getValue(n - 1, i);
    // }

    int solution1(void)
    {
        int n;
        while (cin >> n && n)
        {
            int result = 0;
            // int m = 0;
            // // 注意，直接for循环会超时。。。
            // for (int i = 1; i <= n; i++)
            // {
            //     m = getValue(n, i);
            //     cout << "row " << n << " col " << i << " is " << m << endl;
            //     if (m % 2 == 0)
            //     {
            //         result = i;
            //         break;
            //     }
            // }
            if (n > 2)
            {
                switch((n - 2) % 4)
                {
                    case 1:
                    case 3:
                        result = 2;
                        break;
                    case 2:
                        result = 3;
                        break;
                    case 0:
                        result = 4;
                        break;
                }
            }

            cout << (result ? result : -1) << endl;
        }

        return 0;
    }
}

// HJ54	表达式求值	字符串数学栈	简单	48.76%
// 难度：***，技巧：**
namespace NiuKeHuaWeiTraining_054
{
    int doCalc(string &s, char op)
    {
        int pos = s.find_first_of(op);
        if (s[pos - 1] < '0' || s[pos - 1] > '9' || s[pos + 1] < '0' || s[pos + 1] > '9')
        {
            if (op != '-')
            {
                return 3;
            }
        }

        int leftStep = 1, rightStep = 1, left = 0, right = 0;

        while (s[pos - leftStep] >= '0' && s[pos - leftStep] <= '9')
        {
            leftStep++;
        }
    //     cout << "leftStep: " << leftStep << endl;
        string tempStr = s.substr(pos + 1 - leftStep, leftStep - 1);
        if (tempStr.size() == 1)
        {
            tempStr = '0' + tempStr;
        }
        left = stoi(tempStr);
    //     left = stoi(s.copy( + 1 - leftStep, leftStep - 1));
        while (s[pos + rightStep] >= '0' && s[pos + rightStep] <= '9')
        {
            rightStep++;
        }
        tempStr = s.substr(pos + 1, rightStep - 1);
        if (tempStr.size() == 1)
        {
            tempStr = '0' + tempStr;
        }
        right = stoi(tempStr);
        int temp(0);
        if (op == '+')
        {
            temp = left + right;
        }
        else if (op == '-')
        {
            temp = left - right;
        }
        else if (op == '*')
        {
            temp = left * right;
        }
        else if (op == '/')
        {
            temp = left / right;
        }

        s = s.replace(pos - leftStep + 1, leftStep + rightStep - 1, to_string(temp));
        return 0;
    }

    int doCheckAndCalc(string s, int &res)
    {
        if (s.find_first_of('(') != std::string::npos)
        {
            if (s.find_last_of(')') != std::string::npos)
            {
                if (doCheckAndCalc(s.substr(s.find_first_of('(') + 1, s.find_last_of(')') - s.find_first_of('(') - 1), res))
                {
                    return 1;
                }
                s = s.replace(s.find_first_of('('), s.find_last_of(')') - s.find_first_of('(') + 1, to_string(res));
                if (doCheckAndCalc(s.substr(s.find_first_of('(') + 1, s.find_last_of(')') - 1), res))
                {
                    return 1;
                }
            }
            else
            {
                return 2;
            }
        }
        else if (s.find('*') != std::string::npos)
        {
            if (doCalc(s, '*'))
            {
                return 4;
            }
            if (doCheckAndCalc(s, res))
            {
                return 5;
            }
        }
        else if (s.find('/') != std::string::npos)
        {
            if (doCalc(s, '/'))
            {
                return 4;
            }
            if (doCheckAndCalc(s, res))
            {
                return 5;
            }
        }
        else if (s.find('+') != std::string::npos)
        {
            if (doCalc(s, '+'))
            {
                return 4;
            }
            if (doCheckAndCalc(s, res))
            {
                return 5;
            }
        }
        else if (s.find('-') != std::string::npos)
        {
            if (doCalc(s, '-'))
            {
                return 4;
            }
            if (doCheckAndCalc(s, res))
            {
                return 5;
            }
        }
        else
        {
            res = stoi(s);
        }

        return 0;
    }

    // 通过率2/11， 不能很好的处理负数问题。
    int solution1(void)
    {
        // include <vector>
        string str;
        cin >> str;

        int i(0);
        while (str[i])
        {
            if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-' && str[i] != '*' && 
                str[i] != '/' && str[i] != '(' && str[i] != ')')
            {
                cout << "str including illegal charactor!" << endl;
                exit(0);
            }
            i++;
        }

        int result;
        int ret = doCheckAndCalc(str, result);
        if (ret)
        {
            cout << "Input error! Error code is " << ret << "." << endl;
            exit(0);
        }
        cout << result << endl;

        return 0;
    }
}

// HJ55	（练习用）挑7	穷举数学	中等	35.77%
// 难度：*，技巧：*, AC, 一次过
namespace NiuKeHuaWeiTraining_055
{
    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            int sum = 0;
            for (int i = 1; i <= n; i++)
            {
                if (i % 7 == 0)
                {
                    sum++;
                    continue;
                }
                
                int j = i;
                while (j)
                {
                    if (j % 10 == 7)
                    {
                        sum++;
                        break;
                    }
                    j /= 10;
                }
            }
            cout << sum << endl;
        }

        return 0;
    }
}

// HJ56	iNOC产品部--完全数计算	数学	简单	38.01%
// 难度：***，技巧：****
// 500000以内只有4个完全数 6 28 496 8128
// 欧拉公式： 如果i是质数，2^i-1也是质数，那么(2^i-1)*2^(i-1)就是完全数
// 解题技巧：需要了解完全数的性质以及特征。见solution2. https://baike.sogou.com/v774869.htm?fromTitle=%E5%AE%8C%E5%85%A8%E6%95%B0
namespace NiuKeHuaWeiTraining_056
{
    int solution1(void)
    {
        int n = 0;
        int mCount[500001] = {0};
        mCount[1] = 0;
        int maxNum = 1;
        while(cin >> n)
        {
            DWORD tStart, tStop;
            tStart = GetTickCount();

            if (n > 500000)
            {
                exit(0);
            }

            if (mCount[n] || n < 6)
            {
                cout << mCount[n] << endl;
                tStop = GetTickCount();
                cout << "NiuKeHuaWeiTraining_056 time elasped " << int(tStop - tStart) << "ms." << endl;
                continue;
            }

            int s = maxNum + 1;
            while (s <= n)
            {
                int sum = 1;
                for (int i = 2; i <= s / 2; i++)
                {
                    if (s % i == 0)
                    {
                        sum += i;
                    }
                }
                if (sum == s)
                {
                    cout << s << endl;
                    mCount[s] = mCount[s-1] + 1;
                }
                else
                {
                    mCount[s] = mCount[s-1];
                }

                s++;
            }
            cout << mCount[n] << endl;
            maxNum = n;
            tStop = GetTickCount();
            cout << "NiuKeHuaWeiTraining_056 time elasped " << int(tStop - tStart) << "ms." << endl;
        }
        
        return 0;
    }

    bool isPrimeNumber(int num)
    {
        for (int i = 2; i <= num / 2 + 1; i++) // 考虑到 num=3时，num/2=1 < i = 2, 因此有+1
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int solution2(void)
    {
        int n;
        while (cin >> n)
        {
            int i = 2;
            int m = 0;
            for (; (pow(2, i) - 1) * pow(2, i - 1) < n; i++)
            {
                if (isPrimeNumber(pow(2, i) - 1)) // 如果2^i - 1 是素数
                {
                    m++;
                    cout << (pow(2, i) - 1) * pow(2, i -1) << endl;
                }
            }
            cout << m << endl;
        }

        return 0;
    }
}

// HJ57	无线OSS－高精度整数加法	字符串	中等	36.07%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_057
{
    int solution1(void)
    {
        string str1, str2;
        while(cin >> str1 >> str2)
        {
            string sSum;
            bool addOneflag = false;
            int count = str1.size() > str2.size() ? str1.size() : str2.size();
            
            // 注意 str1.size()是unsigned 类型，需要强制转为int型！！！
            for (int i = str1.size() - 1, j = str2.size() - 1; i >= int(str1.size() - count), j >= int(str2.size() - count); i--, j--)
            {
                int a = 0, b = 0, s = 0;
                if (i >= 0 && j >= 0)
                {
                    a = str1[i] - '0';
                    b = str2[j] - '0';
                }
                else if (i >= 0)
                {
                    a = str1[i] - '0';
                    b = 0;
                }
                else
                {
                    a = 0;
                    b = str2[j] - '0';
                }
                s = a + b;
                if (addOneflag)
                {
                    s += 1;
                    addOneflag = false;
                }
                if (s > 9)
                {
                    addOneflag = true;
                    s -= 10;
                }
                sSum = char('0' + s) + sSum;
            }
            
            if (addOneflag)
            {
                sSum = '1' + sSum;
            }
            
            cout << sSum << endl;
        }

        return 0;
    }
}

// HJ58	输入n个整数，输出其中最小的k个	数组	较难	27.33%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_058
{
    int solution1(void)
    {
        int n, k;
        while (cin >> n >> k)
        {
            vector<int> v(n, 0);
            for (auto &i : v)
            {
                cin >> i;
            }
            sort(v.begin(), v.end());
            
            cout << v[0];
            for (int i = 1; i < k; i++)
            {
                cout << ' ' << v[i];
            }
            cout << endl;
        }
        return 0;
    }
}

// HJ59	找出字符串中第一个只出现一次的字符	字符串	中等	25.22%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_059
{
    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            int i = 0;
            bool find = false;
            while (i < str.size())
            {
                if (str.find_first_of(str[i]) == i && str.find_last_of(str[i]) == i)
                {
                    cout << str[i] << endl;
                    find = true;
                    break;
                }
                i++; // 注意i++以退出循环！！！
            }
            
            if (find == false)
            {
                cout << -1 << endl;
            }
        }
        return 0;
    }
}

// HJ60	查找组成一个偶数最接近的两个素数	穷举数学	中等	36.63%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_060
{
    // #include <iostream>
    // #include <vector>
    // using namespace std;

    bool isPrimeNumer(int n)
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int solution1(void)
    {
        int n;
        while(cin >> n)
        {
            vector<int> a;
            vector<int> b;
            a.clear();
            b.clear();
            
            for (int i = n / 2; i >= 1; i--)
            {
                if (isPrimeNumer(i))
                {
                    a.push_back(i);
                }
            }
            for (int j = n / 2; j < n; j++)
            {
                if (isPrimeNumer(j))
                {
                    b.push_back(j);
                }
            }
            
            int gap = n;
            int x = 0, y = 0;
            for (int i = 0; i < a.size(); i++)
            {
                for (int j = 0; j < b.size(); j++)
                {
                    if (a[i] + b[j] == n)
                    {
                        int temp = b[j] - a[i];
                        if (temp < gap)
                        {
                            gap = temp;
                            x = a[i];
                            y = b[j];
                        }
                    }
                }
            }
            
            cout << x << endl << y << endl;

        }
        return 0;
    }

    int solution2(void)
    {
        int n;
        while (cin >> n)
        {
            int h = n / 2;
            while (isPrimeNumer(h) == false || isPrimeNumer(n - h) == false)
            {
                h--;
            }
            cout << h << endl << n - h << endl;
        }
        return 0;
    }

    int solution3(void)
    {
        int n;
        while (cin >> n)
        {
            int h = n / 2; // 题目条件是任何一个偶数，因此这里不必分开奇数偶数的情况。。。
            if (n % 2 == 0)
            {
                for (int i = 0; i < h; i++)
                {
                    if (isPrimeNumer(h - i) && isPrimeNumer(h + i))
                    {
                        cout << h - i << endl << h + i << endl;
                        break;
                    }
                }
            }
        }
        return 0;
    }
}

// HJ61	放苹果	递归动态规划	简单	39.13%
// 难度：***，技巧：****
// 技巧： 问题分解：可分为两种情况，一种是带有空盘子；另一种是没有空盘子，则转化为每个盘子的苹果数都减1，再递归求解。
// solutin1是自己第一次做的，fail；solution2是参考别人的答案，pass；solution3是几天后自己做的，pass。
namespace NiuKeHuaWeiTraining_061
{
    // int calMethods(int m, int n)
    // {
    //     int ret = 0;

    //     if (n == 1)
    //     {
    //         return 1;
    //     }

    //     if (m % 2 == 0)
    //     {
    //         for (int i = 0; i <= m / 2; i++)
    //         {
    //             cout << "m=" << m << ", n=" << n << ", i=" << i << endl;
    //             ret += calMethods(i, n - 1);
    //         }
    //     }

    //     if (m % 2 == 1)
    //     {
    //         for (int i = 0; i <= m / (n - 1) + 1; i++)
    //         {
    //             if (i == m / 2 + 1)
    //             {
    //                 cout << "m=" << m << ", n=" << n << ", i=" << i << endl;
    //                 ret += calMethods(i, n - 1) - 1;
    //             }
    //             else
    //             {
    //                 cout << "m=" << m << ", n=" << n << ", i=" << i << endl;
    //                 ret += calMethods(i, n - 1);
    //             }
    //         }
    //     }

    //     return ret;
    // }
    // int solution1(void) // 暴力求解，通过率2/10，不推荐！
    // {
    //     int m, n;
    //     while(cin >> m >> n)
    //     {
    //         int sum = 0;
    //         sum += calMethods(m, n);
    //         cout << sum << endl;
    //     }

    //     return 0;
    // }
    int calulatePlaceMethods(int m, int n)
    {
        if (m < 0 || n < 0)
        {
            return 0;
        }
        else if (m == 1 || n == 1)
        {
            return 1;
        }
        else
        {
            return calulatePlaceMethods(m, n - 1) + calulatePlaceMethods(m - n, n);
        }
        
    }

    int solution2(void)
    {
        int m, n;
        while (cin >> m >> n)
        {
            int sum;
            sum = calulatePlaceMethods(m, n);
            cout << sum << endl;
        }
        return 0;
    }

    int Q(int m, int n)
    {
        if (n == 1 || m == 0)    return 1;
        else if (m < n)    return Q(m, m);
        else     return Q(m, n - 1) + Q(m - n, n);
    }

    int solution3(void)
    {
        int m = 0, n = 0;
        while (cin >> m >> n)    cout << Q(m, n) << endl;
        return 0;
    }
}

// HJ62	查找输入整数二进制中1的个数	位运算	简单	41.51%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_062
{
    int solution1(void)
    {
        int n;
        while (cin >> n)
        {
            int sum = 0;
            while (n)
            {
                n = n & (n - 1);
                sum++;
            }
            cout << sum << endl;
        }

        return 0;
    }
}

// HJ63	DNA序列	字符串	中等	33.95%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_063
{
    int solution1(void)
    {
        string str;
        int n;
        while (cin >> str >> n)
        {
            if (n > str.size())
            {
                return -1;
            }
            float ratio = 0.0;
            int pos = 0;
            for (int i = 0; i < str.size() - n; i++)
            {
                int CGCount = 0;
                for ( int j = i; j < i + n; j++)
                {
                    if (str[j] == 'C' || str[j] == 'G')
                    {
                        CGCount++;
                    }
                    else if(str[j] != 'A' && str[j] != 'T')
                    {
                        return -1;
                    }
                }
                float tempRatio = float(CGCount) / n;
                if (ratio < tempRatio)
                {
                    ratio = tempRatio;
                    pos = i;
                }
            }
            
            cout << str.substr(pos, n) << endl;
        }
        return 0;
    }
}

// HJ64	MP3光标位置	数组	中等	27.60%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_064
{
    struct PAGEINFO
    {
        int firstSong;
        int currentSong;
    };

    int solution1(void)
    {
        int n;
        while(cin >> n)
        {
            string str;
            cin >> str;
            PAGEINFO pgInfo;
            pgInfo.firstSong = 1;
            pgInfo.currentSong = 1;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == 'U')
                {
                    if (n < 5 && pgInfo.currentSong == 1)
                    {
                        pgInfo.firstSong = 1;
                        pgInfo.currentSong = n;
                    }
                    else if (pgInfo.currentSong == 1)
                    {
                        pgInfo.firstSong = n - 3;
                        pgInfo.currentSong = n;
                    }
                    else if (pgInfo.currentSong != pgInfo.firstSong)
                    {
                        pgInfo.currentSong--;
                    }
                    else if (pgInfo.currentSong == pgInfo.firstSong)
                    {
                        pgInfo.firstSong--;
                        pgInfo.currentSong--;
                    }
                }
                else if (str[i] == 'D')
                {
                    if (n < 5 && pgInfo.currentSong == n)
                    {
                        pgInfo.firstSong = 1;
                        pgInfo.currentSong = 1;
                    }
                    else if (pgInfo.currentSong == n)
                    {
                        pgInfo.firstSong = 1;
                        pgInfo.currentSong = 1;
                    }
                    else if (pgInfo.currentSong != pgInfo.firstSong + 3)
                    {
                        pgInfo.currentSong++;
                    }
                    else if (pgInfo.currentSong == pgInfo.firstSong + 3)
                    {
                        pgInfo.firstSong++;
                        pgInfo.currentSong++;
                    }
                }
            }
            if (n > 3)
            {
                cout << pgInfo.firstSong << ' ' << pgInfo.firstSong + 1 << ' ' << pgInfo.firstSong + 2 << ' ' << pgInfo.firstSong + 3 << endl;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (i != n - 1)
                    {
                        cout << pgInfo.firstSong + i << ' ';
                    }
                    else
                    {
                        cout << pgInfo.firstSong + i << endl;
                    }
                }
            }
            cout << pgInfo.currentSong << endl;
        }
        return 0;
    }
}

// HJ65	查找两个字符串a,b中的最长公共子串	字符串	中等	31.07%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_065
{
    int solution1(void)
    {
        string str1, str2;
        while (cin >> str1 >> str2)
        {
            string subs;
            string shortStr = str1.size() < str2.size() ? str1 : str2;
            for (int i = 0; i < str1.size(); i++)
            {
                for (int j = 0; j < str2.size(); j++)
                {
                    if (str1[i] == str2[j])
                    {
                        for (int k = 1; k < str1.size() - i, k < str2.size() - j; k++)
                        {
                            if (str1[i + k] == str2[j + k])
                            {
                                if (k >= subs.size())
                                {
                                    subs = str1.substr(i, k + 1);
                                }
                                else if (k + 1 == subs.size())
                                {
                                    if (shortStr.find(subs) > shortStr.find(str1.substr(i, k + 1)))
                                    {
                                        subs = str1.substr(i, k + 1);
                                    }
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
            cout << subs << endl;
        }
        return 0;
    }
}

// HJ66	配置文件恢复	字符串	简单	36.90%
// 难度：**，技巧：*
namespace NiuKeHuaWeiTraining_066
{
    int solution1(void)
    {
        // map<string, string> m;
        // m.insert(make_pair<string, string>("reset", "reset what"));
        // m.insert(make_pair<string, string>("reset board", "board fault"));
        // m.insert(make_pair<string, string>("board add", "where to add"));
        // m.insert(make_pair<string, string>("board delete", "no board at all"));
        // m.insert(make_pair<string, string>("reboot backplane", "impossible"));
        // m.insert(make_pair<string, string>("backplane abort", "install first"));
        // // m["board add"] = "where to add1";

        // for (map<string, string>::iterator it = m.begin(); it != m.end(); it++)
        // {
        //     int i = 20 - it->first.length();
        //     cout << it->first;
        //     switch (int(i / 16))
        //     {
        //         case 4:
        //             cout << "\t ";
        //         case 3:
        //             cout << "\t ";
        //         case 2:
        //             cout << "\t ";
        //         case 1:
        //             cout << "\t ";
        //         case 0:
        //             cout << "\t ";
        //             break;
        //     }
        //     cout << ": " << it->second << endl;
        // }

        string cmd1 = "reset";
        string cmd2_1[5] = {"reset", "board", "board", "reboot", "backplane"};
        string cmd2_2[5] = {"board", "add", "delete", "backplane", "abort"};
        string execute1 = "reset what";
        string execute2[5] = {"board fault", "where to add", "no board at all", "impossible", "install first"};
        string unknown = "unknown command";

        string str;
        str.clear();
        while (getline(cin, str))
        {
            // char str[20];
            // memset(str, 0, 20);
            // 注意：使用scanf时，需要用char s[n]的形式，并且使用前先清空！ 使用char* s或者string s都会出现意想不到的的情况。
            // scanf 会在遇到空格时停在输入，本题不适合使用scanf
            // scanf("%s", str); 

            // cout << str << endl;
            // map<string, string>::iterator iter = m.find(str);
            // if (iter != m.end())
            // {
            //     cout << iter->second << endl;
            // }
            if (str.find(" ") != std::string::npos)
            {
                string str1 = str.substr(0, str.find_first_of(" "));
                string str2 = str.substr(str.find_first_of(" ") + 1);
                int n = 0;
                bool find = false;
                for (int i = 0; i < 5; i++)
                {
                    if (strncmp(cmd2_1[i].c_str(), str1.c_str(), str1.size()) == 0)
                    {
                        if ((strncmp(cmd2_2[i].c_str(), str2.c_str(), str2.size()) == 0))
                        {
                            n = i;
                            if (!find)
                            {
                                find = true;
                            }
                            else
                            {
                                find = false;
                                break;
                            }
                        }
                    }
                }
                if (find)
                {
                    cout << execute2[n] << endl;
                    continue;
                }
                else
                {
                    cout << unknown << endl;
                    continue;
                }
            }
            else
            {
                if (strncmp(str.c_str(), cmd1.c_str(), str.size()) == 0)
                {
                    cout << execute1 << endl;
                    continue;
                }
                else
                {
                    cout << unknown << endl;
                    continue;
                }
            }
            str.clear();
        }
        return 0;
    }
}

// HJ67	24点游戏算法	搜索dfs	中等	31.96%
// namespace NiuKeHuaWeiTraining_067
// {
//     int solution1(void)
//     {
//         return 0;
//     }
// }

// HJ68	成绩排序	排序	较难	21.02%
// 难度：***，技巧：***, fail, 解决相同成绩的情况下保证原来的次序，注意使用冒泡排序更稳妥
namespace NiuKeHuaWeiTraining_068
{
    struct USER
    {
        string name;
        int score;
        bool operator < (USER u)
        {
            return score < u.score;
        }
    };

    int solution1(void)
    {
        int n, r;
        while (cin >> n >> r)
        {
            vector<USER> user;
            for (int i = 0; i < n; i++)
            {
                USER u;
                cin >> u.name >> u.score;
                user.push_back(u);
            }
            
            if (r == 0)
            {
    //             stable_sort(user.begin(), user.end());
                for (int i = 0; i < user.size(); i++)
                {
                    for (int j = 0; j < user.size() - i - 1; j++)  // 冒泡排序。
                    {
                        if (user[j] < user[j + 1])
                        {
                            swap(user[j], user[j + 1]);
                        }
                    }
                }
            }
            else if (r == 1)
            {
                for (int i = 0; i < user.size(); i++)
                {
                    for (int j = 0; j < user.size() - i - 1; j++)
                    {
                        if (user[j + 1] < user[j])
                        {
                            swap(user[j + 1], user[j]);
                        }
                    }
                }
            }
            for (int i = 0; i < user.size(); i++)
            {
                cout << user[i].name << ' ' << user[i].score << endl;
            }
        }
        return 0;
    }
}

// HJ69	矩阵乘法	数组	中等	36.60%
// 难度：*，技巧：**
namespace NiuKeHuaWeiTraining_069
{
    int solution1(void) // TODO: 待改进！！！数组和vector还不够灵活。。
    {
        int x = 0, y = 0, z = 0;
        while (cin >> x >> y >> z)
        {
            vector<vector<int>> mat1;
            vector<vector<int>> mat2;
            int temp = 0;
            vector<int> vt;
            mat1.clear();
            mat2.clear();
            vt.clear();
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    cin >> temp;
                    vt.push_back(temp);
                }
                mat1.push_back(vt);
                vt.clear();
            }
            
            vt.clear();
            for (int i = 0; i < y; i++)
            {
                for (int j = 0; j < z; j++)
                {
                    cin >> temp;
                    vt.push_back(temp);
                }
                mat2.push_back(vt);
                vt.clear();
            }
            
            vector<vector<int>> res;
            vt.clear();
            res.clear();
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < z; j++)
                {
                    int value = 0;
                    for (int k = 0; k < y; k++)
                    {
                        value += mat1[i][k] * mat2[k][j];
                    }
                    vt.push_back(value);
                }
                res.push_back(vt);
                vt.clear();
            }
            
            for (int i = 0; i < x; i++)
            {
                int j = 0;
                for (; j < z - 1; j++)
                {
                    cout << res[i][j] << ' ';
                }
                cout << res[i][j] << endl;
            }
        }
        return 0;
    }

    int solution2(void) // 精简，参考答案
    {
        int x = 0, y = 0, z = 0;
        while (cin >> x >> y >> z)
        {
            int a[x][y], b[y][z], c[x][z];
            for (int i = 0; i < x; i++)
                for (int j = 0; j < y; j++)
                    cin >> a[i][j];
            
            for (int i = 0; i < y; i++)
                for (int j = 0; j < z; j++)
                    cin >> b[i][j];
            
            for (int i = 0; i < x; i++)
            {
                for (int k = 0; k < z; k++)
                {
                    c[i][k] = 0; // 初始化
                    for (int j = 0; j < y; j++)
                    {
                        c[i][k] += a[i][j] * b[j][k];
                    }
                    if (k) cout << ' ';
                    cout << c[i][k];
                }
                cout << endl;
            }
            
        }
        return 0;
    }
}

// HJ70	矩阵乘法计算量估算	字符串	中等	35.98%
// 难度：***，技巧：**, 运行错误！疑似内存泄漏！！
// namespace NiuKeHuaWeiTraining_070
// {
//     unsigned int countSum(string &s, vector<vector<unsigned int>> &n)
//     {
//         unsigned int sum = 0;
//         int j = 0;
//         for (int k = 0; k < s.size(); k++)
//         {
//             if (s[k] >= 'A' && s[k] <= 'A')
//             {
//                 s[k] = 'A' + j;
//                 j++;
//             }
//         }
//         while (s.find('(') != std::string:: npos)
//         {
//             unsigned int endPos = s.find_first_of(')');
//             unsigned int startPos = s.substr(0, endPos).find_last_of('(');
//             string temp = s.substr(startPos + 1, endPos - startPos - 1);
//             sum += countSum(temp, n);
//             s = s.substr(0, startPos) + 'A' + s.substr(endPos + 1); // This 'A' will be auto adjusted to suitable letter.
//         }
//         j = 0;
//         for (int k = 0; k < s.size(); k++)
//         {
//             if (s[k] >= 'A' && s[k] <= 'A')
//             {
//                 s[k] = 'A' + j;
//                 j++;
//             }
//         }
//         unsigned int i = 0;
//         while (i + 1 < s.size())
//         {
//             sum += n[0][s[i] - 'A'] * n[1][s[i] - 'A'] * n[1][s[i + 1] - 'A'];
//             n[1][s[i] - 'A'] = n[1][s[i + 1] - 'A'];
//             for (int k = i; k < n[0].size() - 1; k++)
//             {
//                 n[1][s[k] - 'A'] = n[1][s[k + 1] - 'A'];
//             }
//             n[0].pop_back();
//             n[1].pop_back();
//             if (i + 2 <= s.size())
//             {
//                 s = s.substr(0, i + 1) + s.substr(i + 2);
//             }
//             else
//             {
//                 s = s.substr(0, i + 1);
//             }
//         }
        
//         return sum;
//     }

//     int solution1(void)
//     {
//         unsigned int count;
//         vector<vector<unsigned int>> num(2);
//         while (cin >> count)
//         {
//             int i = count;
//             while (i--)
//             {
//                 unsigned int m, n;
//                 cin >> m >> n;
//                 num[0].push_back(m);
//                 num[1].push_back(n);
//             }
//             string method;
//             cin >> method;
//             cout << countSum(method, num) << endl;
//             num.clear();
//         }

//         return 0;
//     }
// }

// HJ71	字符串通配符	字符串	中等	34.01%
// 难度：***，技巧：***， 最高通过率80%
namespace NiuKeHuaWeiTraining_071
{
    int solution1(void)
    {
        string str1, str2;
        while (getline(cin, str1))
        {
            getline(cin, str2);
            bool result = true;
            
            while (str1.find('*') != std::string::npos)
            {
                int startPos = str1.find_first_of('*');
                string tempsubStr1 = str1.substr(startPos + 1);

                int endPos = tempsubStr1.find_first_of('?'); // '?' is prior than '*'
                if (endPos != std::string::npos)
                {
                    string subStr1 = tempsubStr1.substr(0, endPos);
                    int tempPos = str2.find(subStr1);
                    if (tempPos == std::string::npos)
                    {
                        result = false;
                        break;
                    }
                    else
                    {
                        str1 = str1.substr(0, startPos) + str1.substr(endPos + 1);
                        str2 = str2.substr(0, tempPos) + str2.substr(tempPos + endPos - startPos + 1);
                        continue;
                    }
                }

                endPos = tempsubStr1.find_first_of('*');
                if (endPos != std::string::npos)
                {
                    endPos = tempsubStr1.find_first_of('*');
                    string subStr1 = tempsubStr1.substr(0, endPos);
                    int tempPos = str2.find(subStr1);
                    if (tempPos == std::string::npos)
                    {
                        result = false;
                        break;
                    }
                    else
                    {
                        str1 = str1.substr(0, startPos) + str1.substr(endPos + 1);
                        str2 = str2.substr(0, tempPos) + str2.substr(tempPos + endPos - startPos + 1);
                        continue;
                    }
                }
                else
                {
                    string subS = str1.substr(startPos + 1);
                    int tempPos = str2.find(subS);
                    if (tempPos == std::string::npos)
                    {
                        result = false;
                        break;
                    }
                    else
                    {
                        str1 = str1.substr(0, startPos);
                        str2 = str1.substr(0, tempPos) + str2.substr(tempPos + subS.size());
                        continue;
                    }
                }
            }
            
            if (result)
            {
                int pos = str1.find('?');
                while (pos != std::string::npos)
                {
                    str1 = str1.substr(0, pos) + str1.substr(pos + 1);
                    str2 = str2.substr(0, pos) + str2.substr(pos + 1);
                    pos = str1.find('?');
                }

                if (str1.size() != str2.size())
                {
                    result = false;
                }
                else if (strncasecmp(str1.c_str(), str2.c_str(), str1.size()) != 0)
                {
                    result = false;
                }
            }
            
            cout << (result ? "true" : "false") << endl;
        }
        return 0;
    }
}

// HJ72	百钱买百鸡问题		简单	37.36%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_072
{
    int getResult()
    {
        for (int i = 75; i < 100; i += 3)
        {
            for (int j = 25; j >= 0; j--)
            {
                for (int k = 20; k >= 0; k--)
                {
                    if ((i + j + k == 100) && (5 * k + 3 * j + i / 3 == 100))
                    {
                        cout << k << " " << j << " " << i << endl;
                    }
                }
            }
        }

        return 0;
    }
    int solution1(void)
    {
        int n = 0;
        cin >> n;

        getResult();

        return 0;
    }

    int solution2(void)
    {
        int n = 0;
        cin >> n;

        for (unsigned int i = 0; i <= 100; i++)
        {
            unsigned int j = (100 - 7 * i) / 4;
            unsigned int k = (300 + 3 * i) / 4;
            if (i + j + k == 100 && 5 * i + 3 * j + k / 3 == 100)
            {
                cout << i << " " << j << " " << k << endl;
            }
        }

        return 0;
    }
}

// HJ73	计算日期到天数转换	字符串	简单	35.13%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_073
{
    bool leapYear(int y) // !!!注意看闰年的定义
    {
        bool flag = false;

        if (y % 4 == 0 && y % 100 != 0)
        {
            flag = true;
        }
        else if (y % 100 == 0 && y % 400 == 0)
        {
            flag = true;
        }

        return flag;
    }
    int solution1(void)
    {
        int y, m, d;
        while (cin >> y >> m >> d)
        {
            int outDay(0);

            if (m < 1 || m > 12 || d < 1 || d > 31 || (m == 2 && d > 29) || (y % 4 == 0 && m == 2 && d > 28))
            {
                return -1;
            }

            switch (m)
            {
                case 12:
                    outDay += d;
                case 11:
                    outDay += (m > 11 ? 30 : d);
                case 10:
                    outDay += (m > 10 ? 31 : d);
                case 9:
                    outDay += (m > 9 ? 30 : d);
                case 8:
                    outDay += (m > 8 ? 31 : d);
                case 7:
                    outDay += (m > 7 ? 31 : d);
                case 6:
                    outDay += (m > 6 ? 30 : d);
                case 5:
                    outDay += (m > 5 ? 31 : d);
                case 4:
                    outDay += (m > 4 ? 30 : d);
                case 3:
                    outDay += (m > 3 ? 31 : d);
                case 2:
                    outDay += (m > 2 ? (leapYear(y) ? 29 : 28) : d);
                case 1:
                    outDay += (m > 1 ? 31 : d);
                    break;
                default:
                    {
                        return -1;
                    }
            }

            cout << outDay << endl;
        }

        return 0;
    }
}

// HJ74	参数解析	字符串	简单	41.46%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_074
{
    int solution1(void)
    {
        string cmd;
        cmd.clear();
        getline(cin, cmd);
        vector<string> vec;
        vec.clear();
        int sum = 0;
        while (cmd.size() > 0)
        {
            if (cmd.find(" ") == 0)
            {
                cmd = cmd.substr(1); // remove the first blank
                continue;
            }

            if (cmd.find_first_of("\"") != std::string::npos && cmd.find_first_of("\"") < cmd.find_first_of(" "))
            {
                cmd = cmd.substr(cmd.find_first_of("\"") + 1);
                vec.push_back(cmd.substr(0, cmd.find_first_of("\"")));
                sum++;
                cmd = cmd.substr(cmd.find_first_of("\"") + 1);
            }
            else if (cmd.find("\"") == std::string::npos && cmd.find(" ") == std::string::npos)
            {
                vec.push_back(cmd);
                sum++;
                cmd.resize(0);
                break;
            }
            else
            {
                vec.push_back(cmd.substr(0, cmd.find_first_of(" ")));
                sum++;
                cmd = cmd.substr(cmd.find_first_of(" ") + 1);
            }
        }

        cout << sum << endl;
        for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
        {
            cout << *it << endl;
        }

        return 0;
    }
}

// HJ75	公共字串计算	字符串	简单	35.10%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_075
{
    int solution1(void)
    {
        string str1;
        string str2;
        getline(cin, str1);
        getline(cin, str2);

        unsigned int len = 0;
        unsigned int i = 0;
        while (i < str1.size())
        {
            unsigned int tempLen = 0;
            unsigned int j = 1;
            while (str2.find(str1.substr(i, j)) != std::string::npos && i + j <= str1.size())
            {
                tempLen = tempLen > j ? tempLen : j;
                len = len > tempLen ? len : tempLen;
                j++;
            }
            cout << str1.substr(i, j - 1) << endl;
            i++;
        }

        cout << len << endl;

        return 0;
    }
}

// HJ76	尼科彻斯定理	数学	简单	37.92%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_076
{
    int solution1(void)
    {
        int n;
        while(cin >> n)
        {
            int start = n * n - n + 1;
            while(n--)
            {
                cout << start;
                start += 2;
                if (n)
                {
                    cout << "+";
                }
            }
            cout << endl;
        }

        return 0;
    }
}

// HJ77	火车进站	栈	较难	36.99%
// namespace NiuKeHuaWeiTraining_077
// {
//     int solution1(void)
//     {
//         return 0;
//     }
// }

// HJ80	整形数组合并	数组排序	较难	27.01%
// 难度：*，技巧：*， pass，一次过，但方法有待提高
namespace NiuKeHuaWeiTraining_080
{
    // #include <set> // 需放在本文件开头才有效，不然放这里编译会报错
    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            vector<int> v(n, 0);
            for (auto &i : v)
            {
                cin >> i;
            }
            int m = 0;
            cin >> m;
            v.resize(m + n);
            for (int i = 0; i < m; i++)
            {
                cin >> v[n + i];
            }
            for (int i = 0; i < v.size(); i++) // 选择排序
            {
                int index = i;
                for (int j = i + 1; j < v.size(); j++)
                {
                    if (v[index] > v[j])
                    {
                        index = j;
                    }
                }
                if (index != i)
                {
                    int tmp = v[i];
                    v[i] = v[index];
                    v[index] = tmp;
                }
                if (i == 0) cout << v[i];
                else if (v[i] > v[i - 1])
                {
                    cout << v[i];
                }
            }
            cout << endl;
        }
        return 0;
    }

    int solution2(void)
    {
        int n = 0;
        int times = 0;
        set<int> s;
        while (cin >> n)
        {
            times++;
            
            for (int i = 0; i < n; i++)
            {
                int tmp = 0;
                cin >> tmp;
                s.insert(tmp);
            }
            if (times == 2)
            {
                for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
                {
                    cout << *iter;
                }
                cout << endl;
                times = 0;
                s.clear();
            }
        }
        return 0;
    }
}

// HJ81	字符串匹配	字符串	较难	25.04%
// 难度：*，技巧：*, 一次过
namespace NiuKeHuaWeiTraining_081
{
    int solution1(void)
    {
        string str1, str2;
        while (getline(cin, str1))
        {
            getline(cin, str2);
            int arr2[26] = {0};

            for (int i = 0; i < str2.size(); i++)
            {
                arr2[str2[i] - 'a']++;
            }
            bool ret = true;
            for (int i = 0; i < str1.size(); i++)
            {
                if (arr2[str1[i] - 'a'] == 0)
                {
                    ret = false;
                    break;
                }
            }
            
            cout << (ret ? "true" : "false") << endl;
        }

        return 0;
    }
}

// HJ82	将真分数分解为埃及分数	搜索数学	困难	34.52%
// 难度：***，技巧：***
namespace NiuKeHuaWeiTraining_082
{
    // #include <iostream>
    // #include <vector>
    // using namespace std;

    bool isABigger(int molA, int denomA, int molB, int denomB)
    {
        return (molA * denomB >= molB * denomA);
    }

    void removeCommonFactor(int &molA, int &denomA)
    {
        int commonFactor = 1;
        for (int i = 2; i < molA; i++)
        {
            if (molA % i == 0 && denomA % i == 0)
            {
                commonFactor *= i;
            }
        }
        molA /= commonFactor;
        denomA /= commonFactor;
    }

    void doMinus(int &molA, int &denomA, int molB, int denomB)
    {
        molA = molA * denomB - molB * denomA;
        denomA = denomB * denomA;
        removeCommonFactor(molA, denomA);
    }

    int solution1(void) // 通过率6/10，自己最开始的思路
    {
        string str;
        while (cin >> str)
        {
            int molecular = stod(str.substr(0, str.find('/')));
            int denominator = stod(str.substr(str.find('/') + 1));
            vector<string> out;
            int n = 1;
            while (n++)
            {
                if (isABigger(molecular, denominator, 1, n))
                {
                    out.push_back("1/" + to_string(n));
                    doMinus(molecular, denominator, 1, n);
                }
                if (molecular == 0)
                {
                    break;
                }
            }
            
            for (int i = 0; i < out.size() - 1; i++)
            {
                cout << out[i] << '+';
            }
            cout << out[out.size() - 1] << endl;
        }
        return 0;
    }

    int solution2(void) // 可以AC。
    {
        string str;
        while (cin >> str)
        {
            // 1. 输入a/b，则有b = a * m + n; n < a;
            // 2. 转换， 可得 (b - n) / a = m; m + 1 = (b - n + a) / a; a/b = (b - n + a)/(b(m + 1)) = 1 / (m + 1) + (a - n) / (b(m + 1));
            int a = stod(str.substr(0, str.find('/')));
            int b = stod(str.substr(str.find('/') + 1));
            vector<string> out;
            int m = 0, n = 0;
            while (1)
            {
                if ( b % (a - 1) == 0 && a != 2) // 这个if直接取巧了， 不要if也可以AC。
                {
                    out.push_back("1/" + to_string(b / (a - 1)));
                    a = 1;
                    out.push_back("1/" + to_string(b));
                    break;
                }
                m = b / a;
                n = b % a;
                out.push_back("1/" + to_string(m + 1));
                a = a - n;
                b = b * (m + 1);
                if (b % a == 0)
                {
                    b /= a;
                    a = 1;
                }
                if (a == 1)
                {
                    out.push_back("1/" + to_string(b));
                    break;
                }
            }
            
            for (int i = 0; i < out.size() - 1; i++)
            {
                cout << out[i] << '+';
            }
            cout << out[out.size() - 1] << endl;
        }
        return 0;
    }
}

// HJ83	二维数组操作	数组	简单	23.05%
// namespace NiuKeHuaWeiTraining_083
// {
//     int solution1(void)
//     {
//         return 0;
//     }
// }

// HJ84	统计大写字母个数	字符串	简单	35.81%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_084
{
    int solution1(void)
    {
        string str;
        str.clear();
        while(getline(cin, str))
        {
            int count = 0;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                {
                    count++;
                }
            }
            cout << count << endl;
            str.clear();
        }

        return 0;
    }
}

// HJ85	字符串运用-密码截取	字符串穷举	简单	34.82%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_085
{
    int solution1(void)
    {
        string str;
        while (cin >> str)
        {
            int len = 0;
            for (int i = 0; i < str.size(); i++)
            {
                for (int j = str.size() - 1; j > i; j--)
                {
                    if (str[i] == str[j])
                    {
                        int k = (j - i) / 2;
                        while (k > 0)
                        {
                            if (str[i + k] != str[j - k])
                            {
                                break;
                            }
                            k--;
                        }
                        if (k == 0)
                        {
                            int tempLen = j - i + 1;
                            // cout << i << "->" << j << "->" << k << ":" << str.substr(i, tempLen) << endl;
                            len = len > tempLen ? len : tempLen;
                        }
                    }
                }
            }
            cout << len << endl;
            str.clear();
        }

        return 0;
    }
}

// HJ86	求最大连续bit数	位运算	简单	35.34%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_086
{
    int solution1(void)
    {
        int num;
        while(cin >> num)
        {
            int len = 0;
            int tempLen = 0;
            while (num > 0)
            {
                if (num & 0x1)
                {
                    tempLen++;
                }
                else
                {
                    tempLen = 0;
                }
                len = len > tempLen ? len : tempLen;
                num >>= 1;
            }
            cout << len << endl;
        }
        return 0;
    }
}

// HJ87	密码强度等级	字符串	简单	29.34%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_087
{
    int solution1(void)
    {
        string password;
        while (cin >> password)
        {
            unsigned int score = 0;
            unsigned int letterTypes = 0; // 0 means no letter; 1 means lowerCase, 2 means upperCase; 3 means both lowerCase and upperCase two types.
            unsigned int digitCounts = 0; // digit counts.
            unsigned int symbolCounts = 0; // symbol counts.
            unsigned int i = 0;
            while (i < password.size())
            {
                if (password[i] >= 'a' && password[i] <= 'z')
                {
                    letterTypes |= 0x1;
                }
                else if (password[i] >= 'A' && password[i] <= 'Z')
                {
                    letterTypes |= 0x2;
                }
                else if (password[i] >= '0' && password[i] <= '9')
                {
                    digitCounts++;
                }
                else if ((password[i] >= 0x21 && password[i] <= 0x2F) || (password[i] >= 0x3A && password[i] <= 0x40) || 
                         (password[i] >= 0x5B && password[i] <= 0x60) || (password[i] >= 0x7B && password[i] <= 0x7E))
                {
                    symbolCounts++;
                }
                i++;
            }

            if (password.size() <= 4)
            {
                score += 5;
            }
            else if (password.size() <= 7)
            {
                score += 10;
            }
            else
            {
                score += 25;
            }
            
            switch(letterTypes)
            {
                case 0:
                    score += 0;
                    break;
                case 1:
                case 2:
                    score += 10;
                    break;
                case 3:
                    score += 20;
                    break;
            }

            switch (digitCounts)
            {
                case 0:
                    score += 0;
                    break;
                case 1:
                    score += 10;
                    break;
                default:
                    score += 20;
                    break;
            }

            switch (symbolCounts)
            {
                case 0:
                    score += 0;
                    break;
                case 1:
                    score += 10;
                    break;
                default:
                    score += 25;
                    break;
            }

            if (digitCounts)
            {
                if (symbolCounts)
                {
                    if (letterTypes == 3)
                    {
                        score += 5;
                    }
                    else if(letterTypes)
                    {
                        score += 3;
                    }
                }
                else if (letterTypes)
                {
                    score += 2;
                }
            }

            // cout << letterTypes << "-" << digitCounts << "-" << symbolCounts << ":" << score << endl;
            if (score >= 90)
            {
                cout << "VERY_SECURE" << endl;
            }
            else if(score >= 80)
            {
                cout << "SECURE" << endl;
            }
            else if(score >= 70)
            {
                cout << "VERY_STRONG" << endl;
            }
            else if(score >= 60)
            {
                cout << "STRONG" << endl;
            }
            else if(score >= 50)
            {
                cout << "AVERAGE" << endl;
            }
            else if(score >= 25)
            {
                cout << "WEAK" << endl;
            }
            else
            {
                cout << "VERY_WEAK" << endl;
            }
        }

        return 0;
    }
}

// HJ88	扑克牌大小	字符串队列链表栈	中等	30.91%
// 难度：**，技巧：**, 本地调试几个用例之后，一次pass。
namespace NiuKeHuaWeiTraining_088
{
    // #include <iostream>
    // using namespace std;

    struct Poker
    {
        int type; // 1 means 1 poker, 2 means 2 pokers, 3 means 3 pokers, 4 means 4 pokers, 5 means sequence.
        int cards; // how many cards.
        // 3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
        // 0 1 2 3 4 5 6  7 8 9 A B C   D     E
        int start; // 0 1 3 4 5 6 7 8 9 A B C D E F
        void clear() {type = 0; cards = 0; start = 0;}
    };

    int cardNumbers(string s)
    {
        int sum = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ' ' && s[i - 1] != ' ')    sum++;
        }
        return sum;
    }

    int getCard(char c)
    {
        int d = 0;
        if (c >= '3' && c <= '9')
        {
            d = c - '3';
        }
        else if (c == 'J')    d = 0x8;
        else if (c == 'Q')    d = 0x9;
        else if (c == 'K')    d = 0xA;
        else if (c == 'A')    d = 0xB;
        else if (c == '2')    d = 0xC;
        
        return d;
    }

    int getStart(string s)
    {
        char c = s[0];
        int d = 0;
        if (s[1] == '0' && s[0] == '1') d = 0x7;
        else 
        {
            if (c >= '3' && c <= '9')
            {
                return c - '3';
            }
            else if (c == 'J')    d = 0x8;
            else if (c == 'Q')    d = 0x9;
            else if (c == 'K')    d = 0xA;
            else if (c == 'A')    d = 0xB;
            else if (c == '2')    d = 0xC;
        }
        
        return d;
    }

    // bool checkSequence(string s)
    // {
    //     int num = cardNumbers(s);
        
    // }

    bool checkCardSame(string s)
    {
        char c = s[0];
        if (c == '0')    return false;
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] != ' ' && s[i] != c)
            {
                if (s[i] == '0' && s[i - 1] == '1')    continue;
                else     return false;
            }
        }
        return true;
    }

    bool savePokerToStruct(string s, Poker &p)
    {
        p.clear();
        int cardNum = cardNumbers(s);
        if (s.find("joker") != std::string::npos)
        {
            if (cardNum == 2 && s.find("JOKER") != std::string::npos)
            {
                p.type = 2;
                p.cards = 2;
                p.start = 0xD;
                return true;
            }
            else if (cardNum == 1)
            {
                p.type = 1;
                p.cards = 1;
                p.start = 0xD;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (s.find("JOKER") != std::string::npos)
        {
            if (cardNum == 1)
            {
                p.type = 1;
                p.cards = 1;
                p.start = 0xE;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (cardNum == 1)
        {
            p.cards = 1;
            p.type = 1;
            if (s.substr(0, 2) == "10")
            {
                p.start = 0x7;
            }
            else
            {
                p.start = getCard(s[0]);
            }
            return true;
        }
        else if (cardNum == 2)
        {
            if (!checkCardSame(s))
            {
                return false;
            }
            p.type = 2;
            p.cards = 2;
            p.start = getStart(s);
            return true;
        }
        else if (cardNum == 3)
        {
            if (!checkCardSame(s))
            {
                return false;
            }
            p.type = 3;
            p.cards = 3;
            p.start = getStart(s);
            return true;
        }
        else if (cardNum == 4)
        {
            if (!checkCardSame(s))
            {
                return false;
            }
            p.type = 4;
            p.cards = 4;
            p.start = getStart(s);
            return true;
        }
        else if (cardNum >= 5)
        {
    //         checkSequence(s); // skip this step
            p.type = 5;
            p.cards = cardNum;
            p.start = getStart(s);
            return true;
        }
        
        return false;
    }

    int doCompare(string s1, string s2)
    {
        int ret = 0;
        Poker p1, p2;
        if (!savePokerToStruct(s1, p1) || !savePokerToStruct(s2, p2))
        {
            ret = 0;
        }
        else if (p1.cards != p2.cards)
        {
            if (p1.cards == 2 && p1.start == 0xD)    ret = 1;
            else if (p2.cards == 2 && p2.start == 0xD)    ret = 2;
            else if (p1.cards == 4)    ret = 1;
            else if (p2.cards == 4)    ret = 2;
            else ret = 0;
        }
        else if (p1.start > p2.start)  ret = 1;
        else if (p1.start < p2.start)  ret = 2;
        else ret = 0;
            
        return ret;
    }

    string strip(string &s)
    {
        while (s[0] == ' ')
        {
            s = s.substr(1);
        }
        while (s[s.size() - 1] == ' ')
        {
            s = s.substr(0, s.size() - 1);
        }
        return s;
    }

    int main(void)
    {
        string str;
        while (getline(cin, str))
        {
            string str1, str2;
            str1 = str.substr(0, str.find('-'));
            str2 = str.substr(str.find('-') + 1);
            strip(str1);
            strip(str2);
            int ret = doCompare(str1, str2);
            if (ret == 0)
            {
                cout << "ERROR" << endl;
            }
            else if (ret == 1)
            {
                cout << str1 << endl;
            }
            else if (ret == 2)
            {
                cout << str2 << endl;
            }
        }
        return 0;
    }
}

// HJ89	24点运算	字符串模拟穷举	困难	14.52%
// 难度：*，技巧：*, 穷举。 pass 13/20, fail 7/20. 答案应该是没有包括所有可能。
namespace NiuKeHuaWeiTraining_089
{
    // #include <iostream>
    // #include <vector>
    // #include <algorithm>
    // using namespace std;

    int doOp(int a, int b, char op)
    {
        if (a <= 0 || b <= 0)    return -1;
        
        if (op == '+')    return a + b;
        else if (op == '-')    return a - b;
        else if (op == '*')    return a * b;
        
        if (op == '/')
        {
            if (a % b == 0)    return a / b;
            else    return -1;
        }
        return -1;
    }

    bool cal(vector<int> &arr, string &out)
    {
        bool ret = false;
        char op[4] = {'+', '-', '*', '/'};
        
        for (int l = 0; l < 4; l++)
        {
            for (int m = 0; m < 4; m++)
            {
                if (m == l) continue;
                for (int n = 0; n < 4; n++)
                {
                    if (n == m || n == l) continue;
                    for (int i = 0; i < 4; i++)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            for (int k = 0; k < 4; k++)
                            {
                                if (doOp(doOp(doOp(arr[l], arr[m], op[i]), arr[n], op[j]), arr[6 - l - m - n], op[k]) == 24)
                                {
                                    out = to_string(arr[l]) + op[i] + to_string(arr[m]) + op[j] + to_string(arr[n]) + op[k] + to_string(arr[6 - l - m - n]);
                                    ret = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return ret;
    }

    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            vector<int> arr(4);
            arr.clear();
            bool error = false;
            transform(str.begin(), str.end(), str.begin(), ::toupper);
            while (str.size())
            {
                string s;
                if (str.find(' ') != std::string::npos)
                {
                    s = str.substr(0, str.find(' '));
                    str = str.substr(str.find(' ') + 1);
                }
                else
                {
                    s = str;
                    str.clear();
                }
                
                if (s == "JOKER")    error = true;
                
                if (error != true)
                {
                    if (s == "J")    arr.push_back(11);
                    else if (s == "Q")    arr.push_back(12);
                    else if (s == "K")    arr.push_back(13);
                    else if (s == "A")    arr.push_back(1);
                    else if (s == "10")    arr.push_back(10);
                    else    arr.push_back(s[0] - '0');
                }
            }
            
            string out;
            if (error)    cout << "ERROR" << endl;
            else if (cal(arr, out))    cout << out << endl;
            else    cout << "NONE" << endl;
        }
        return 0;
    }
}

// HJ90	合法IP	字符串链表栈队列	中等	29.79%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_090
{
    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            bool res = true;
            
            int n = 0, i = 3;
            
            while (i--)
            {
                n = stoi(str.substr(0, str.find_first_of('.')));

                res = (n > 255 || n < 0 ? false : res);
                str = str.substr(str.find_first_of('.') + 1);
            }
            n = stoi(str);
            res = (n > 255 ? false : res);
            
            cout << (res ? "YES" : "NO") << endl;
        }
        return 0;
    }
}

// HJ91	201301 JAVA 题目2-3级	字符串	简单	35.60%
// 难度：***，技巧：***
// namespace NiuKeHuaWeiTraining_091
// {
//     int solution1(void)
//     {
//         int n = 0, m = 0;
//         while (cin >> n >> m)
//         {
//             int methods = 2 * ((n + 1) * (m + 1) - n - m - 2);
//             if (n == 1 || m == 1)
//             {
//                 methods += 1;
//             }
//             cout << methods << endl;
//         }
//         return 0;
//     }
// }

// HJ92	在字符串中找出连续最长的数字串	字符串	较难	23.67%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_092
{
    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            unsigned len = 0;
            string output, temp;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    temp += str[i];
                }
                else
                {
                    if (temp.size() > len)
                    {
                        len = temp.size();
                        output = temp;
                    }
                    else if (temp.size() == len)
                    {
                        output += temp;
                    }
                    temp.clear();
                }
                
                if (i == str.size() - 1)
                {
                    if (temp.size() > len)
                    {
                        len = temp.size();
                        output = temp;
                    }
                    else if (temp.size() == len)
                    {
                        output += temp;
                    }
                }
            }
            
            cout << output << "," << len << endl;
        }
        return 0;
    }
}

// HJ93	201301 JAVA题目0-1级	字符串递归	较难	29.22%
// 难度：***，技巧：*, 深度优先搜索，递归。
// namespace NiuKeHuaWeiTraining_093
// {
//     int solution1(void)
//     {
//         return 0;
//     }
// }

// HJ94	记票统计		较难	22.30%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_094
{
    int solution1(void) // 不能用map，因为map的排序会影响输出结果
    {
        int n = 0;
        while (cin >> n)
        {
            vector<string> v(n);
            vector<int> w(n, 0);
            for (auto &i : v)
            {
                string tmp;
                cin >> tmp;
                i = tmp;
            }
            int t = 0, invalid = 0;
            cin >> t;
            for (int i = 0; i < t; i++)
            {
                string tmp;
                cin >> tmp;
                bool find = false;
                for (int j = 0; j < v.size(); j++)
                {
                    if (v[j] == tmp)
                    {
                        w[j]++;
                        find = true;
                        break;
                    }
                }
                
                if (!find)
                {
                    invalid++;
                }
            }
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " : " << w[i] << endl;
            }
            cout << "Invalid : " << invalid << endl;
        }
        return 0;
    }
}

// HJ95	人民币转换	字符串	较难	27.31%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_095
{
    const string str1[10] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    const string str2[10] = {"角", "分", "整", "元", "拾", "佰", "仟", "万", "亿", "人民币"};

    string getNumber(int n, string unit)
    {
        string str;
        if (n % 10)
        {
            str += (str1[n % 10] + unit);
        }
        else
        {
            str += (str1[0]);
        }
        return str;
    }

    int solution1(void)
    {
        double rmb;

        while (cin >> rmb)
        {
            string rmbFormat;
            string decimalPart;
            if (to_string(rmb).find('.') != std::string::npos)
            {
                string temp = to_string(rmb);
                int t = stoi(temp.substr(temp.find('.') + 1, 2));
                if (t >= 10)
                {
                    decimalPart += (str1[t / 10] + str2[0]);
                }
                if (t % 10)
                {
                    decimalPart += (str1[t % 10] + str2[1]);
                }
                if (t == 0)
                {
                    decimalPart += str2[2];
                }
            }
            else
            {
                decimalPart += str2[3];
            }
            
            int rmbIntergerPart = int(rmb);
            while (rmbIntergerPart % 100000000)
            {
                int temp = rmbIntergerPart % 100000000;
                if (temp % 10 == 0)
                {
                    rmbFormat = str2[3] + rmbFormat;
                }
                else
                {
                    rmbFormat = getNumber(temp % 10, str2[3]) + rmbFormat;
                }
                if (temp / 10) temp /= 10; else break;
                rmbFormat = getNumber(temp % 10, str2[4]) + rmbFormat;
                if (temp / 10) temp /= 10; else break;
                rmbFormat = getNumber(temp % 10, str2[5]) + rmbFormat;
                if (temp / 10) temp /= 10; else break;
                rmbFormat = getNumber(temp % 10, str2[6]) + rmbFormat;
                if (temp / 10) temp /= 10; else break;
                if (temp % 10 == 0)
                {
                    rmbFormat = str2[7] + rmbFormat;
                }
                else
                {
                    rmbFormat = getNumber(temp % 10, str2[7]) + rmbFormat;
                }
                if (temp / 10) temp /= 10; else break;
                rmbFormat = getNumber(temp % 10, str2[4]) + rmbFormat;
                if (temp / 10) temp /= 10; else break;
                rmbFormat = getNumber(temp % 10, str2[5]) + rmbFormat;
                if (temp / 10) temp /= 10; else break;
                rmbFormat = getNumber(temp % 10, str2[6]) + rmbFormat;
                if (temp / 10) temp /= 10; else break;
                
                if (rmbIntergerPart / 100000000)
                {
                    rmbFormat = str2[8] + rmbFormat;
                    rmbIntergerPart /= 100000000;
                }
                else
                {
                    break;
                }
            }
            
            while (rmbFormat.find("零零") != std::string::npos)
            {
                rmbFormat = rmbFormat.substr(0, rmbFormat.find("零零")) + rmbFormat.substr(rmbFormat.find("零零") + 3);
            }
            if (rmbFormat.find("零") == 0)
            {
                rmbFormat = rmbFormat.substr(3);
            }
            while (rmbFormat.find("壹拾") != std::string::npos)
            {
                rmbFormat = rmbFormat.substr(0, rmbFormat.find("壹拾")) + rmbFormat.substr(rmbFormat.find("壹拾") + 3);
            }
            if (rmbFormat.find("零元") != std::string::npos)
            {
                rmbFormat = rmbFormat.substr(0, rmbFormat.find("零元")) + rmbFormat.substr(rmbFormat.find("零元") + 3);
            }
            rmbFormat = str2[9] + rmbFormat + decimalPart;
            cout << rmbFormat << endl;
        }
        return 0;
    }
}

// HJ96	表示数字	字符串	中等	27.92%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_096
{
    int solution1(void)
    {
        string str;
        while(getline(cin, str))
        {
            int i = 0;
            string sOut;
            bool digit = false;
            while (i < str.size())
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    if (digit == false)
                    {
                        if (str[i + 1] < '0' || str[i + 1] > '9')
                        {
                            sOut.push_back('*');
                            sOut.push_back(str[i]);
                            sOut.push_back('*');
                        }
                        else
                        {
                            sOut.push_back('*');
                            sOut.push_back(str[i]);
                            digit = true;
                        }
                    }
                    else
                    {
                        if (str[i + 1] < '0' || str[i + 1] > '9')
                        {
                            sOut.push_back(str[i]);
                            sOut.push_back('*');
                            digit = false;
                        }
                        else
                        {
                            sOut.push_back(str[i]);
                        }
                    }
                }
                else
                {
                    sOut.push_back(str[i]);
                }
                i++;
            }
            cout << sOut << endl;
        }
        return 0;
    }
}

// HJ97	记负均正	数组	较难	16.52%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_097
{
    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            int sum = 0, negative = 0, positive = 0;
            for (int i = 0; i < n; i++)
            {
                int tmp = 0;
                cin >> tmp;
                if (tmp < 0)
                {
                    negative++;
                }
                else if (tmp > 0)
                {
                    sum += tmp;
                    positive++;
                }
            }
            printf("%d %.1f\n", negative, sum / float(positive));
        }
        return 0;
    }
}

// HJ98	自动售货系统	字符串	中等	21.87%
// 难度：*，技巧：*, 通过率 7/10，有一组是预期输出error 写成 erro, 这样通不过没办法。
// 搭建一套简易的交易框架，可以培养一定的整体架构意识。
namespace NiuKeHuaWeiTraining_098
{
    #include <iostream>
    #include <string.h>
    using namespace std;

    const int PRICE_A1 = 2;
    const int PRICE_A2 = 3;
    const int PRICE_A3 = 4;
    const int PRICE_A4 = 5;
    const int PRICE_A5 = 8;
    const int PRICE_A6 = 6;

    const string SUCCESS_INITIALIZATION_MSG     = "S001:Initialization is successful";
    const string SUCCESS_PAYMENT_MSG            = "S002:Pay success";
    const string SUCCESS_DEALING_MSG            = "S003:Buy success";

    const string ERR_DENOMINATION_MSG           = "E002:Denomination error";
    const string ERR_CHANGE_NOT_ENOUGH_MSG      = "E003:Change is not enough, pay fail";
    const string ERR_ALL_GOODS_SOLD_OUT_MSG     = "E005:All the goods sold out";
    const string ERR_GOOD_NOT_EXIST_MSG         = "E006:Goods does not exist";
    const string ERR_GOODS_SOLD_OUT_MSG         = "E007:The goods sold out";
    const string ERR_LACK_OF_BALANCE_MSG        = "E008:Lack of balance";
    const string ERR_WORK_FAILURE_MSG           = "E009:Work failure";
    const string ERR_PARAM_ERROR_MSG            = "E010:Parameter error";

    enum ERRORCODE
    {
        ERR_SUCCESS = 0x000,
        
        ERR_DENOMINATION,         // E002
        ERR_CHANGE_NOT_ENOUGH,    // E003
        ERR_ALL_GOODS_SOLD_OUT,   // E005
        ERR_GOOD_NOT_EXIST,       // E006
        ERR_GOODS_SOLD_OUT,       // E007
        ERR_LACK_OF_BALANCE,      // E008
        ERR_WORK_FAILURE,         // E009
        ERR_PARAM_ERROR,          // E010
        
        ERR_LAST_ERROR = 0x200    // do not set error code more than this!
    };

    enum SUCCESCODE // DO NOT RETURN THIS SUCCESS CODE!!!
    {
        SUCCESS_INITIALIZATION = 0x666, // S001
        SUCCESS_PAYMENT,                // S002
        SUCCESS_DEALING,                // S003
        
        SUCCESS_LAST_CODE = 0x900       // do not set success code more than this!
    };

    #define getStatusMsg(status) status##_MSG

    struct Good
    {
        Good(string s, int p) : name(s), price(p) { mount = 0; }
        const string name;
        const unsigned int price;
        private:
            unsigned int mount;
        public:
            void setMount(unsigned int m) {this->mount = m;}
            string getName() {return this->name;}
            unsigned int getPrice() {return this->price;}
            unsigned int getMount() {return this->mount;}
            void printInfo() {cout << this->getName() << " price: " << this->getPrice() << "; mount: " << this->getMount() << "." << endl;}
    };

    struct Cash
    {
        Cash(string s) : name(s) {}
        const string name;
        private:
            unsigned int count;
        public:
            void setCount(unsigned int c) {this->count = c;}
            string getName() {return this->name;}
            unsigned int getCount() {return this->count;}
            void printInfo() {cout << this->getName() << " left " << this->getCount() << "." << endl;}
    };

    struct Buy
    {
        Buy() {balance = 0; currentGood = "";}
        private:
            int balance;
            string currentGood;
        public:
            void setBalance(int q) {this->balance = q;}
            void setGood(string s) {this->currentGood = s;}
            int getBalance() {return this->balance;}
            string getGood() {return this->currentGood;}
            void initBuy() {this->balance = 0; this->currentGood = "";}
    };

    class ErrorClass
    {
        public:
            ErrorClass() {errCode = ERR_SUCCESS; errMsg = "";}
            int errCode;
            string errMsg;
            void resetError() {errCode = 0; errMsg = "";}
    };

    Good A1("A1", 2), A2("A2", 3), A3("A3", 4), A4("A4", 5), A5("A5", 8), A6("A6", 6);
    Cash C1("1"), C2("2"), C3("5"), C4("10");
    int sumCash() {return (C1.getCount() + 2 * C2.getCount() + 5 * C3.getCount() + 10 * C4.getCount());}
    int sumGoodCount() {return (A1.getMount() + A2.getMount() + A3.getMount() + A4.getMount() + A5.getMount() + A6.getMount());}

    Buy buy;
    ErrorClass err;

    #define ERRC err.errCode
    #define ERRM err.errMsg

    string strip(string &str, char c = ' ')
    {
        while (str.size() > 0)
        {
            if (str[0] == c)
            {
                str = str.substr(1);
            }
            else if(str[str.size() - 1] == c)
            {
                str = str.substr(0, str.size() - 1);
            }
            else
            {
                break;
            }
        }
        return str;
    }

    #define CHECK_ERROR_RETONER(result); \
            {int temp = result;\
            if (temp != ERR_SUCCESS)\
            {\
                err.errCode = temp;\
                return temp;}\
            }

    #define SEND_STATUS_MSG_RETURN(STATUS_CODE) \
            {cout << getStatusMsg(STATUS_CODE) << endl;\
            return STATUS_CODE;}\
        
    #define SEND_STATUS_BALANCE_MSG_NORET(STATUS_CODE, n) \
            {cout << getStatusMsg(STATUS_CODE) << ",balance=" << n << endl;}\

    void printInfo(bool goods, bool cash)
    {
        if (goods)
        {
            A1.printInfo();
            A2.printInfo();
            A3.printInfo();
            A4.printInfo();
            A5.printInfo();
            A6.printInfo();
        }
        if (cash)
        {
            C1.printInfo();
            C2.printInfo();
            C3.printInfo();
            C4.printInfo();
        }
    }

    void initSystem(string initString)
    {
        strip(initString);
        string amountStr = initString.substr(0, initString.find(" "));
        string leftCashStr = initString.substr(initString.find(" ") + 1);
        
        string s1;
        unsigned int n1 = 0;
        s1 = amountStr.substr(0, amountStr.find_first_of("-"));
        n1 = stoi(s1);
        A1.setMount(n1);
        amountStr = amountStr.substr(amountStr.find_first_of("-") + 1);
        
        s1 = amountStr.substr(0, amountStr.find_first_of("-"));
        n1 = stoi(s1);
        A2.setMount(n1);
        amountStr = amountStr.substr(amountStr.find_first_of("-") + 1);
        
        s1 = amountStr.substr(0, amountStr.find_first_of("-"));
        n1 = stoi(s1);
        A3.setMount(n1);
        amountStr = amountStr.substr(amountStr.find_first_of("-") + 1);
        
        s1 = amountStr.substr(0, amountStr.find_first_of("-"));
        n1 = stoi(s1);
        A4.setMount(n1);
        amountStr = amountStr.substr(amountStr.find_first_of("-") + 1);
        
        s1 = amountStr.substr(0, amountStr.find_first_of("-"));
        n1 = stoi(s1);
        A5.setMount(n1);
        amountStr = amountStr.substr(amountStr.find_first_of("-") + 1);
        
        s1 = amountStr;
        n1 = stoi(s1);
        A6.setMount(n1);
        
        s1 = leftCashStr.substr(0, leftCashStr.find_first_of("-"));
        n1 = stoi(s1);
        C1.setCount(n1);
        leftCashStr = leftCashStr.substr(leftCashStr.find_first_of("-") + 1);
        
        s1 = leftCashStr.substr(0, leftCashStr.find_first_of("-"));
        n1 = stoi(s1);
        C2.setCount(n1);
        leftCashStr = leftCashStr.substr(leftCashStr.find_first_of("-") + 1);
        
        s1 = leftCashStr.substr(0, leftCashStr.find_first_of("-"));
        n1 = stoi(s1);
        C3.setCount(n1);
        leftCashStr = leftCashStr.substr(leftCashStr.find_first_of("-") + 1);
        
        s1 = leftCashStr;
        n1 = stoi(s1);
        C4.setCount(n1);
        
        buy.initBuy();
        
    //     printInfo(true, true);
        
        cout << getStatusMsg(SUCCESS_INITIALIZATION) << endl;
        
        return ;
    }

    int buyGood(Good g)
    {
        if (g.getMount() == 0)
        {
            SEND_STATUS_MSG_RETURN(ERR_GOODS_SOLD_OUT);
        }
        else
        {
            if (buy.getBalance() < int(g.getPrice()))
            {
                SEND_STATUS_MSG_RETURN(ERR_LACK_OF_BALANCE);
            }
            buy.setGood(g.getName());
            int b = buy.getBalance() - g.getPrice();
            buy.setBalance(b);
            g.setMount(g.getMount() - 1);
    //         SEND_SUCCESS_MSG_NORET(SUCCESS_DEALING, buy.getBalance());
        }
        
        return ERRC;
    }

    int buyGoods(string cmd)
    {
        strip(cmd);
        if (cmd == "A1")
        {
            CHECK_ERROR_RETONER(buyGood(A1));
        }
        else if (cmd == "A2")
        {
            CHECK_ERROR_RETONER(buyGood(A2));
        }
        else if (cmd == "A3")
        {
            CHECK_ERROR_RETONER(buyGood(A3));
        }
        else if (cmd == "A4")
        {
            CHECK_ERROR_RETONER(buyGood(A4));
        }
        else if (cmd == "A5")
        {
            CHECK_ERROR_RETONER(buyGood(A5));
        }
        else if (cmd == "A6")
        {
            CHECK_ERROR_RETONER(buyGood(A6));
        }
        else
        {
            cout << getStatusMsg(ERR_GOOD_NOT_EXIST) << endl;
            return ERR_GOOD_NOT_EXIST;
        }
        
        SEND_STATUS_BALANCE_MSG_NORET(SUCCESS_DEALING, buy.getBalance());
        return ERRC;
    }

    int returnCash()
    {
        int ret[4] = {0};
        if (buy.getBalance() == 0)
        {
            SEND_STATUS_MSG_RETURN(ERR_WORK_FAILURE);
        }
        
        while (buy.getBalance() > 0)
        {
            if (buy.getBalance() >= 10 && C4.getCount() > 0)
            {
                ret[3]++;
                buy.setBalance(buy.getBalance() - 10);
                C4.setCount(C4.getCount() - 1);
            }
            else if (buy.getBalance() >= 5 && C3.getCount() > 0)
            {
                ret[2]++;
                buy.setBalance(buy.getBalance() - 5);
                C3.setCount(C3.getCount() - 1);
            }
            else if (buy.getBalance() >= 2 && C2.getCount() > 0)
            {
                ret[1]++;
                buy.setBalance(buy.getBalance() - 2);
                C2.setCount(C2.getCount() - 1);
            }
            else if (buy.getBalance() >= 1 && C1.getCount() > 0)
            {
                ret[0]++;
                buy.setBalance(buy.getBalance() - 1);
                C1.setCount(C1.getCount() - 1);
            }
        }
        
        if (buy.getBalance() < 0)
        {
            SEND_STATUS_MSG_RETURN(ERR_WORK_FAILURE);
        }
        
        cout << "1 yuan coin number=" << ret[0] << endl;
        cout << "2 yuan coin number=" << ret[1] << endl;
        cout << "5 yuan coin number=" << ret[2] << endl;
        cout << "10 yuan coin number=" << ret[3] << endl;
        
        return ERRC;
    }

    int checkBoxCash(int n)
    {
        if (n > 2 && sumCash() < n)
        {
            SEND_STATUS_MSG_RETURN(ERR_CHANGE_NOT_ENOUGH);
        }

        return ERRC;
    }
    int checkRestGoods()
    {
        if (sumGoodCount() == 0)
        {
            SEND_STATUS_MSG_RETURN(ERR_ALL_GOODS_SOLD_OUT);
        }
        return ERRC;
    }
    int putCash(string cmd)
    {
        strip(cmd);
        int n = stoi(cmd);
        if (n == 5 || n == 10)
        {
            CHECK_ERROR_RETONER(checkBoxCash(n));
            CHECK_ERROR_RETONER(checkRestGoods());
        }
        else if (n == 1 || n == 2)
        {
            CHECK_ERROR_RETONER(checkRestGoods());
        }
        else
        {
            CHECK_ERROR_RETONER(ERR_DENOMINATION);
        }
        buy.setBalance(n + buy.getBalance());
        SEND_STATUS_BALANCE_MSG_NORET(SUCCESS_PAYMENT, buy.getBalance());
        return ERRC;
    }

    int quiryInfo(string cmd)
    {
    //     strip(cmd);
        if (cmd.size() <= 1 || cmd[0] != ' ')
        {
            SEND_STATUS_MSG_RETURN(ERR_PARAM_ERROR);
        }
        strip(cmd);
        if (cmd.size() > 1)
        {
            SEND_STATUS_MSG_RETURN(ERR_PARAM_ERROR);
        }
        int n = stoi(cmd);
        if (n == 1)
        {
            cout << A1.getName() << " " << A1.getPrice() << " " << A1.getMount() << endl;
            cout << A2.getName() << " " << A2.getPrice() << " " << A2.getMount() << endl;
            cout << A3.getName() << " " << A3.getPrice() << " " << A3.getMount() << endl;
            cout << A4.getName() << " " << A4.getPrice() << " " << A4.getMount() << endl;
            cout << A5.getName() << " " << A5.getPrice() << " " << A5.getMount() << endl;
            cout << A6.getName() << " " << A6.getPrice() << " " << A6.getMount() << endl;
        }
        else if(n == 0)
        {
            cout << "1 yuan coin number=" << C1.getCount() << endl;
            cout << "2 yuan coin number=" << C2.getCount() << endl;
            cout << "5 yuan coin number=" << C3.getCount() << endl;
            cout << "10 yuan coin number=" << C4.getCount() << endl;
        }
        else
        {
            SEND_STATUS_MSG_RETURN(ERR_PARAM_ERROR);
        }
        return ERRC;
    }

    int solution1(void)
    {
    //     string initString = "0-0-0-0-0-0 0-0-0-0";
    //     initSystem(initString);
        
        string line;
        while (getline(cin, line))
        {
            while (line.size() > 0)
            {
                err.resetError();
                string cmd;
                if (line.find(";") != std::string::npos)
                {
                    cmd = line.substr(0, line.find(";"));
                    line = line.substr(line.find(";") + 1);
                }
                else
                {
                    cmd = line;
                }
                strip(cmd);
                if (cmd.size() == 0)
                {
                    break;
                }
                switch (cmd[0])
                {
                    case 'b':
                        buyGoods(cmd.substr(1));
                        break;
                    case 'c':
                        returnCash();
                        break;
                    case 'p':
                        putCash(cmd.substr(1));
                        break;
                    case 'q':
                        quiryInfo(cmd.substr(1));
                        break;
                    case 'r':
                        initSystem(cmd.substr(1));
                        break;
                }
            }
        }
        
        return 0;
    }
}

// HJ99	自守数		中等	32.89%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_099
{
    // #include <iostream>
    // #include <cmath>
    // using namespace std;

    int countDigit(int n)
    {
        int ret = 0;
        while (n > 0)
        {
            ret++;
            n /= 10;
        }
        return ret;
    }

    int solution2(void)
    {
        int n = 0;
        while (cin >> n)
        {
            int sum = 0;
            while(n >= 0)
            {
                int m = pow(10, countDigit(n));
                m = n * n % m;
                if (m == n) sum++;
                n--;
            }
            cout << sum << endl;
        }
        return 0;
    }

    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            int sum = 0;
            while(n >= 0)
            {
                int m = n * n;
                int t = n;
                while (t > 0)
                {
                    if (t % 10 != m % 10)    break;
                    t = t / 10;
                    m = m / 10;
                }
                if (t == 0) sum++;
                n--;
            }
            cout << sum << endl;
        }
        return 0;
    }
}

// HJ100	等差数列	数学	简单	33.07%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_100
{
    int solution1(void)
    {
        int num;
        while (cin >> num)
        {
            cout << 2 * num + 3 * num * (num - 1) / 2 << endl;
        }
        return 0;
    }
}

// HJ101	输入整型数组和排序标识，对其元素按照升序或降序进行排序	排序	较难	22.12%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_101
{
// #include <iostream>
// #include <vector>
// using namespace std;

    void bubbleSort(vector<int> &v, int flag)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size() - i - 1; j++)
            {
                if (flag)
                {
                    if (v[j] < v[j + 1])
                    {
                        swap(v[j], v[j + 1]);
                    }
                }
                else
                {
                    if (v[j] > v[j + 1])
                    {
                        swap(v[j], v[j + 1]);
                    }
                }
            }
        }
        return;
    }

    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            vector<int> v(n, 0);
            for (auto &i : v)
            {
                int tmp = 0;
                cin >> tmp;
                i = tmp;
            }
            int flag = 0;
            cin >> flag;
            bubbleSort(v, flag);
            cout << v[0];
            for (int i = 1; i < v.size(); i++)
            {
                cout << ' ' << v[i];
            }
            cout << endl;
        }
        return 0;
    }
}

// HJ102	字符统计	字符串排序	中等	24.33%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_102
{
    int solution1(void)
    {
        string str;
        while (getline(cin, str))
        {
            int arr[36] = {0}; // 'a' - 'z' + '0' - ’9', 使用前一定要初始化！！！
            int i = 0;
            while (i < str.size())
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                {
                    arr[str[i] - 'a' + 10]++;
                }
                else if (str[i] >= '0' && str[i] <= '9')
                {
                    arr[str[i] - '0']++;
                }
                else
                {
                    return -1;
                }
                i++;
            }
            
            int tempNum = 0;
            int tempIndex = 0;
            for(int i = 0; i < 36; i++)
            {
                for (int j = 0; j < 36; j++)
                {
                    if (tempNum < arr[j])
                    {
                        tempNum = arr[j];
                        tempIndex = j;
                    }
                }
                arr[tempIndex] = -1;
                if (tempNum > 0)
                {
                    cout << char(tempIndex < 10 ? (tempIndex + '0') : (tempIndex - 10 + 'a'));
                }
                tempNum = tempIndex = 0;
            }
            cout << endl;
        }
        return 0;
    }
}

//  HJ103	Redraiment的走法	排序	中等	22.67%
// 难度：***，技巧：***, 初始fail, 参考了答案。DP问题，重点在于dp[i] = max(dp[i], 1 + dp[j]);
namespace NiuKeHuaWeiTraining_103
{
    int solution1(void)
    {
        int n = 0;
        while (cin >> n)
        {
            vector<int> v(n, 0);
            int i = 0;
            for (auto &i : v)
            {
                cin >> i;
            }
            vector<int> dp(n, 1);
            for (int i = 0; i < v.size(); i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (v[i] > v[j])
                    {
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                }
            }
            int m = 0;
            i = 0;
            for (const auto &i : dp)
            {
                m = (m < i ? i : m);
            }
            cout << m << endl;
        }
        return 0;
    }
}

// HJ105	记负均正II	数组	较难	22.78%
// 难度：*，技巧：*, pass
namespace NiuKeHuaWeiTraining_105
{
    // #include <iomanip>
    int solution1(void)
    {
        int n = 0;
        int sum = 0, negative = 0, positive = 0;
        
        while (cin >> n)
        {
            if (n < 0)    negative++;
            else
            {
                sum += n;
                positive++;
            }
        }
    //     if (positive)    printf("%d\n%.1f\n", negative, sum / float(positive));
        cout.setf(ios::fixed);
        if (positive)    cout << negative << endl << setprecision(1) << fixed << sum / float(positive) << endl;
        else    cout << negative << endl << "0.0" << endl;
        
        return 0;
    }
}

// HJ106	字符逆序	字符串	简单	38.60%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_106
{
    int solution1(void)
    {
        string str;
        getline(cin, str);
        int i = str.size();
        while (i-- >= 0)
        {
            cout << str[i];
        }
        cout << endl;

        return 0;
    }

    int solution2(void)
    {
        string str;
        getline(cin, str);
        reverse(str.begin(), str.end());
        cout << str << endl;

        return 0;
    }
}

// HJ107	求解立方根	数学二分	中等	28.37%
// 难度：*，技巧：**, fail. 考虑二分法就够了，不要想太多。。。
namespace NiuKeHuaWeiTraining_107
{
    double cube(double &n)
    {
        return (n) * (n) * (n);
    }

    double cubeRoot(double n)
    {
        double left = min(min(n, -n), -1.0);
        double right = max(max(n, -n), 1.0);
        double m = 0.0;
        while (right - left > 0.001)
        {
            m = (right + left) / 2.0;
            if (cube(m) > n)
            {
                right = m;
            }
            else if (cube(m) < n)
            {
                left = m;
            }
        }
        return m;
    }

    int solution1(void)
    {
        double n = 0.0;
        while (cin >> n)
        {
            printf("%.1f\n", cubeRoot(n));
        }
        return 0;
    }
}

// HJ108	求最小公倍数	递归数学	简单	31.95%
// 难度：*，技巧：*
namespace NiuKeHuaWeiTraining_108
{
    int solution1(void)
    {
        int m, n;
        while (cin >> m >> n)
        {
            int commonMultiple = m > n ? m : n;
            int largestMultiple = m * n;
            while (commonMultiple <= largestMultiple)
            {
                if ((commonMultiple % m == 0) && (commonMultiple % n == 0))
                {
                    cout << commonMultiple << endl;
                    break;
                }
                commonMultiple++;
            }
        }

        return 0;
    }

    int solution2(void)
    {
        int m, n;
        while (cin >> m >> n)
        {
            int c = 1;
            int small = m < n ? m : n;
            for (int i = 2; i <= small; i++)
            {
                if (m % i == 0 && n % i == 0)
                {
                    c *= i;
                    m /= i;
                    n /= i;
                    small /= i;
                }
            }
            c = c * m * n;
            cout << c << endl;
        }

        return 0;
    }
}

int main(void)
{
    time_t tbegin, tend;
    tm* tblock;

    time(&tbegin);
    DWORD tStart, tStop;
    tStart = GetTickCount();
    // NiuKeHuaWeiTraining_001::solution1(); // 简单
    // NiuKeHuaWeiTraining_001::solution2();

    // NiuKeHuaWeiTraining_002::solution1(); // 简单


    // NiuKeHuaWeiTraining_004::solution1(); // 简单
    // NiuKeHuaWeiTraining_004::solution2();
    // NiuKeHuaWeiTraining_004::solution3();
    // NiuKeHuaWeiTraining_004::solution4();

    // NiuKeHuaWeiTraining_005::solution1(); // 简单
    // NiuKeHuaWeiTraining_005::solution2();

    // NiuKeHuaWeiTraining_006::solution1(); // 中等

    // NiuKeHuaWeiTraining_007::solution1(); // 入门
    // NiuKeHuaWeiTraining_007::solution2();

    // NiuKeHuaWeiTraining_008::solution1(); // 中等

    // NiuKeHuaWeiTraining_009::solution1(); // 中等

    // NiuKeHuaWeiTraining_010::solution1(); // 中等

    // NiuKeHuaWeiTraining_011::solution1(); // 简单
    // NiuKeHuaWeiTraining_011::solution2();

    // NiuKeHuaWeiTraining_012::solution1();


    // NiuKeHuaWeiTraining_014::solution1(); // 中等
    // NiuKeHuaWeiTraining_014::solution2(); // 中等

    // NiuKeHuaWeiTraining_015::solution1(); // 入门
    // NiuKeHuaWeiTraining_015::solution2();


    // NiuKeHuaWeiTraining_017::solution1(); // 较难

    // NiuKeHuaWeiTraining_018::solution1(); // 困难

    // NiuKeHuaWeiTraining_019::solution1(); // 困难

    // NiuKeHuaWeiTraining_020::solution1(); // 较难

    // NiuKeHuaWeiTraining_021::solution1(); // 中等

    // NiuKeHuaWeiTraining_022::solution1(); // 简单
    // NiuKeHuaWeiTraining_022::solution2();

    // NiuKeHuaWeiTraining_023::solution1(); // 较难

    // NiuKeHuaWeiTraining_025::solution1(); // 较难

    // NiuKeHuaWeiTraining_026::solution1(); // 中等

    // NiuKeHuaWeiTraining_027::solution1(); // 困难


    // NiuKeHuaWeiTraining_029::solution1(); // 较难

    // NiuKeHuaWeiTraining_030::solution1(); // 较难

    // NiuKeHuaWeiTraining_031::solution1(); // 困难
    // NiuKeHuaWeiTraining_031::solution2(); // 困难

    // NiuKeHuaWeiTraining_032::solution1(); // 较难
    // NiuKeHuaWeiTraining_032::solution2(); // 较难

    // NiuKeHuaWeiTraining_033::solution1(); // 较难

    // NiuKeHuaWeiTraining_034::solution1(); // 中等
    // NiuKeHuaWeiTraining_034::solution2(); // 中等


    // NiuKeHuaWeiTraining_036::solution1(); // 中等
    // NiuKeHuaWeiTraining_036::solution2(); // 中等


    // NiuKeHuaWeiTraining_037::solution1(); // 简单
    // NiuKeHuaWeiTraining_037::solution2();

    // NiuKeHuaWeiTraining_038::solution1(); // 中等


    // NiuKeHuaWeiTraining_040::solution1(); // 中等

    // NiuKeHuaWeiTraining_041::solution1(); // 困难
    // NiuKeHuaWeiTraining_041::solution2(); // 困难


    // NiuKeHuaWeiTraining_044::solution1(); // 困难

    // NiuKeHuaWeiTraining_045::solution1(); // 中等

    // NiuKeHuaWeiTraining_046::solution1(); // 中等


    // NiuKeHuaWeiTraining_051::solution1(); // 较难


    // NiuKeHuaWeiTraining_053::solution1(); // 简单

    // NiuKeHuaWeiTraining_054::solution1(); // 简单

    // NiuKeHuaWeiTraining_055::solution1(); // 中等

    // NiuKeHuaWeiTraining_056::solution1(); // 简单
    // NiuKeHuaWeiTraining_056::solution2();

    // NiuKeHuaWeiTraining_057::solution1(); // 中等


    // NiuKeHuaWeiTraining_060::solution1(); // 中等
    // NiuKeHuaWeiTraining_060::solution2(); // 中等
    // NiuKeHuaWeiTraining_060::solution3(); // 中等

    // NiuKeHuaWeiTraining_061::solution1(); // 简单
    // NiuKeHuaWeiTraining_061::solution2();
 
    // NiuKeHuaWeiTraining_062::solution1(); // 简单

    // NiuKeHuaWeiTraining_063::solution1(); // 中等

    // NiuKeHuaWeiTraining_064::solution1(); // 中等


    // NiuKeHuaWeiTraining_066::solution1(); // 简单

    // NiuKeHuaWeiTraining_069::solution1(); // 中等
    // NiuKeHuaWeiTraining_069::solution2(); // 中等

    // NiuKeHuaWeiTraining_070::solution1(); // 中等

    // NiuKeHuaWeiTraining_071::solution1(); // 中等


    // NiuKeHuaWeiTraining_072::solution1(); // 简单
    // NiuKeHuaWeiTraining_072::solution2();

    // NiuKeHuaWeiTraining_073::solution1(); // 简单

    // NiuKeHuaWeiTraining_074::solution1(); // 简单

    // NiuKeHuaWeiTraining_075::solution1(); // 简单

    // NiuKeHuaWeiTraining_076::solution1(); // 简单


    // NiuKeHuaWeiTraining_080::solution1(); // 较难
    // NiuKeHuaWeiTraining_080::solution2(); // 较难


    // NiuKeHuaWeiTraining_082::solution1(); // 困难


    // NiuKeHuaWeiTraining_084::solution1(); // 简单

    // NiuKeHuaWeiTraining_085::solution1(); // 简单

    // NiuKeHuaWeiTraining_086::solution1(); // 简单

    // NiuKeHuaWeiTraining_087::solution1(); // 简单


    // NiuKeHuaWeiTraining_090::solution1(); // 中等


    // NiuKeHuaWeiTraining_094::solution1(); // 较难


    // NiuKeHuaWeiTraining_097::solution1(); // 较难

    // NiuKeHuaWeiTraining_098::solution1(); // 中等


    // NiuKeHuaWeiTraining_100::solution1(); // 简单

    // NiuKeHuaWeiTraining_101::solution1(); // 较难

    // NiuKeHuaWeiTraining_102::solution1(); // 中等


    // NiuKeHuaWeiTraining_105::solution1(); // 较难


    // NiuKeHuaWeiTraining_106::solution1(); // 简单
    // NiuKeHuaWeiTraining_106::solution2();

    // NiuKeHuaWeiTraining_107::solution1(); // 中等

    // NiuKeHuaWeiTraining_108::solution1(); // 简单
    // NiuKeHuaWeiTraining_108::solution1();


    time(&tend);
    tStop = GetTickCount();
    // cout << "Time elapsed: " << difftime(tend, tbegin) << "s." << endl;
    cout << "Time elapsed: " << int(tStop - tStart) << "ms." << endl;
    return 0;
}
