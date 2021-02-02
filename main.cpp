#include "main.h"
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
void RN_thread(int n, std::vector<int> *res_arr)
{
    (*res_arr).push_back(fib(n));
}
int main()
{
    std::vector<int> response;
    std::vector<std::thread> threads_arr;
    int threads = 10;
    for (size_t i = 0; i < threads; i++)
    {
        threads_arr.push_back(std::thread(RN_thread, 10, &response));
    }
    while (threads != response.size())
    {
        PRINT("Processing...");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    for (size_t i = 0; i < response.size(); i++)
    {
        threads_arr[i].detach();
        PRINT("thread[" << i << "]: returned " << response[i] << " (int) (thread detached)");
    }
    std::cin.get();
}
