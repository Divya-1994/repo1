#include <iostream>
#include <chrono>

using namespace std;

void fun1(int n);
void fun2(int n);
void fun3(int n);
void fun4(int n);

int main()
{	
	int n;
	cout<<"Enter the Number :"<<endl;
	cin>>n;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::nanoseconds elapsed_seconds;
    std::time_t end_time;
    cout << "fun1"<<endl<<endl;
	start = chrono::high_resolution_clock::now();
	fun1(n);
	end = chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
	elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	 cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " ns\n"<< endl << endl;
	
    cout << "fun2"<<endl<<endl;
	start = chrono::high_resolution_clock::now();
	fun2(n);
	end = chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
	elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	 cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " ns\n"<< endl << endl;
	
    cout << "fun3"<<endl<<endl;
	start = chrono::high_resolution_clock::now();
	fun3(n);
	end = chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
	elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	 cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " ns\n"<< endl << endl;
	
    cout << "fun4"<<endl<<endl;
	start = chrono::high_resolution_clock::now();
	fun4(n);
	end = chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
	elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	 cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " ns\n"<< endl << endl;
	
	
}

void fun1(int n)
{
	int x = 0;
	for(int i=1; i <= n; i++)
	{
		for(int j=1; j <= i; j++)
		{
			x = x + 1;
		}
	}
}

void fun2(int n)
{
	int x = 0;
	int j = n;
	while (j >= 1)
	{
		for(int i=1; i <= j; i++)
		{
			x = x + 1;
		}
		j = n/2;
		if(x > 10000000)
			break;	
	}
}

void fun3(int n)
{
	int x = 0;
	for(int i=1; i <= n; i++)
	{
		for(int j=1; j <= i; j++)
		{
			for(int k=1; k <= i; k++)
				{
				x = x + 1;
				}
		}
	}
}

void fun4(int n)
{
	int x = 0;
	int i = n;
	while (i >= 1)
	{
		for(int j=1; j <= n; j++)
		{
			x = x + 1;
			i = i/2;
		}	
	}
}



