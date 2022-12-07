#include <iostream>
#include <vector>
#include <crtdbg.h>

using namespace std;

// 총 수열의 수
#define ARR_COUNT 128

// 제공받은 압축률
float compressionRatio = 4.0f;

// 압축 후의 수열 개수
int afterCompressCount = (int)(((float)ARR_COUNT / compressionRatio) * 0.5f);


// 손실률 계산
double GetRMSE(const int arr[], const vector<pair<int, int>> RLE)
{
	int releaseRLE[ARR_COUNT] = { 0, };

	int curCount = 0;
	int curIndex = 0;
	for (int i = 0; i < RLE.size(); ++i)
	{
		int curCount = RLE[i].first;
		for (int j = 0; j < curCount; ++j)
			releaseRLE[curIndex++] = RLE[i].second;
	}
	double result = 0;
	for (int j = 0; j < ARR_COUNT; ++j)
	{
		// 출력용 ======================================
		if (j % 16 == 0)
			cout << '\n';
		printf("%2d ", releaseRLE[j]);
		// ============================================
		result += (arr[j] - releaseRLE[j]) * (arr[j] - releaseRLE[j]);
	}
	return sqrt(result / ARR_COUNT);
}


void MakeRLE(const int arr[ARR_COUNT])
{
	//RLE 된 수열
	vector<pair<int, int>> RLE_set;

	double avg = arr[0];
	int sum = 0;
	int RLE_count = 0;
	double threshold = 0;

	while (RLE_set.size() != afterCompressCount)
	{
		RLE_set.clear();
		avg = arr[0];
		sum = 0;
		RLE_count = 0;
		for (int i = 0; i < ARR_COUNT; ++i)
		{
			if (avg - arr[i] >= threshold || arr[i] - avg >= threshold)
			{
				RLE_set.push_back(make_pair(RLE_count, int(round(avg))));
				sum = 0;
				avg = 0.0f;
				RLE_count = 0;
			}
			sum += arr[i];
			avg = (double)sum / (double)++RLE_count;
		}
		if (RLE_count != 0)
			RLE_set.push_back(make_pair(RLE_count, int(round(avg))));
		threshold += 0.001;
	}
	
	// 출력용 ======================================

	for (int i = 0; i < RLE_set.size(); ++i)
	{
		if (i % 8 == 0)
			cout << '\n';
		printf("%2d ", RLE_set[i].first);
		printf("%2d ", RLE_set[i].second);
	}


	cout << "\n\n===================압축 푼 수열=====================\n";

	// ============================================
	cout << "\n\nRMSE(=손실률) : " << GetRMSE(arr, RLE_set) << '\n';
}

int main()
{
	int* arr2 = new int[400];
	//_CrtSetBreakAlloc();	
	// 16 x 8
	int arr[ARR_COUNT] =
	{
		49, 49, 50, 52, 49, 47, 47, 46, 44, 42, 42, 38, 38, 38, 36, 34,
		33, 33, 33, 32, 34, 38, 42, 41, 42, 42, 40, 41, 40, 38, 38, 37,
		37, 39, 41, 40, 40, 40, 40, 42, 45, 47, 47, 46, 46, 46, 47, 47,
		47, 47, 46, 44, 43, 39, 36, 34, 34, 32, 30, 29, 30, 31, 31, 31,
		30, 28, 25, 23, 24, 22, 22, 25, 25, 27, 31, 33, 35, 37, 38, 39,
		39, 40, 40, 41, 40, 40, 40, 40, 39, 38, 37, 35, 35, 34, 33, 32,
		31, 30, 30, 29, 29, 28, 27, 27, 28, 27, 25, 26,  0,  0, 90, 90,
		90, 90, 90, 91, 90, 88, 87, 84, 80, 78, 83, 89, 91, 90, 89, 92
	};

	cout << "===================주어진 수열=====================\n";

	for (int j = 0; j < ARR_COUNT; ++j)
	{
		int temp = arr[j];
		if (j % 16 == 0)
			cout << '\n';
		printf("%2d ", arr[j]);
	}

	cout << "\n\n===================압축한 수열=====================\n";

	MakeRLE(arr);

	
	_CrtDumpMemoryLeaks();

	return 0;
}