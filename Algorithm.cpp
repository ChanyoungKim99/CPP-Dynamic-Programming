#include <iostream>
#include <map>
#include <string>

// Dynamic Programming

// 피보나치 수열의 40번째수는?
// 20 * 20 모눈종이를 이동하는 모든 경우의 수는?
// 주어진 동전들로 720원을 만들기 위해서는 최소 몇개의 동전 사용?
// 문자열 목록이 주어졌을 때 "Hello"를 만들기 위한 최소의 방법은?

// n번째 피보나치 수를 구해봅시다.
// 점화식 F(n) = F(n-1) + F(n-2) 
// 단, F(1) = 1, F(2) = 1

int64_t Fibonacci(int n)        // 기존의 int보다 넓은 64비트 변수 int
{
    // base case
    if (n == 1 || n == 2)
    {
        return 1;
    }

    // recursive case
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//------------------------------------------------------------------------------
 

// (5) = xxx
// (4) = yyy
// 같이 key와 value값을 가지는 자료구조 map 사용 

using history = std::map<int, int64_t>;

int64_t Fibonacci_DP(int n, history& h)
{
                            // map의 count 함수는 키의 갯수를 구하는 함수
    if (h.count(n) == 1)    // key의 갯수가 1일 때 = 백업된 값 존재 = 되돌려줌
    {
        return h[n];
    }

    // base case
    if (n <= 2)
    {
        return 1;
    }

    // recursive case
    h[n] = Fibonacci_DP(n - 1, h) + Fibonacci_DP(n - 2, h);     // 백업

    return h[n];
}
// Time Complexity  : O(n)
// Space Complexity : O(n)


// m행 n열 크기의 사각형이 주어졌을 때,
// 좌상단에서 시작해 우하단으로 이동하는 모든 경우의 수
// 단, 오른쪽/아래쪽으로만 이동가능
// Time Complexity : 

int64_t FindWays(int m, int n)
{
    // base case
    // m 과 n이 1일 때 + m 또는 n이 0일 때
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if ( m == 1 && n == 1 )
    {
        return 1;
    }

    // recursive case
    return FindWays(m - 1, n) + FindWays(m, n - 1);
}

// F(2,3) = xxx
// F(2,1) = yyy
// key 값이 std::pair인 map 구조
// key 값을 string으로 해놔도 가능하다 ex) "2, 3"

using history2 = std::map<std::string, int64_t>;

int64_t FindWays_DP(int m, int n, history2& h)
{
    std::string key = std::to_string(m) + "," + std::to_string(n);

    if (h.count(key) == 1)      // 백업한 값 계산하지 않고 사용하기!
    {
        return h[key];
    }

    std::string rkey = std::to_string(n) + "," + std::to_string(m);

    if (h.count(rkey) == 1)
    {
        return h[rkey];
    }

    // base case
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (m == 1 && n == 1)
    {
        return 1;
    }

    // recursive case
    h[key] = FindWays_DP(m - 1, n, h) + FindWays_DP(m, n - 1, h);
    return h[key];
}
// Time Complexity  : 
// Space Complexity : 

int main()
{
    //Brute Force
    std::cout << Fibonacci(7) << std::endl;
    // Fibonacci(50)을 구할 경우, 1000조가 넘는 수가 나온다
    // 더 빠른 방법이 필요하다

    // Dynamic Programming
    history h;
    std::cout << Fibonacci_DP(60, h) << std::endl;

    // 매우 빠르다!

    std::cout << FindWays(2, 3) << std::endl;

    history2 h2;
    std::cout << FindWays_DP(20, 20, h2) << std::endl;
}

