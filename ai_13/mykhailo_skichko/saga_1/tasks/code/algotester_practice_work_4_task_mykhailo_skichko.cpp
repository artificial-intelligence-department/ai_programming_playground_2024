// https://algotester.com/uk/ArchiveProblem/DisplayWithFile/26

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int MAX_N = 101;

std::vector<int> adj[MAX_N];
bool visited[MAX_N];
int A[MAX_N], B[MAX_N];

void dfs(int node, std::vector<int> &component)
{
	visited[node] = true;
	component.push_back(node);
	for (int neighbor : adj[node])
	{
		if (!visited[neighbor])
		{
			dfs(neighbor, component);
		}
	}
}

int main()
{
	int N, M;
	std::cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> A[i] >> B[i];
	}

	for (int i = 0; i < M; ++i)
	{
		int X, Y;
		std::cin >> X >> Y;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}

	memset(visited, false, sizeof(visited));
	int totalRemainingTea = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i])
		{
			std::vector<int> component;
			dfs(i, component);

			int totalBrought = 0, totalConsumed = 0;
			for (int node : component)
			{
				totalBrought += A[node];
				totalConsumed += B[node];
			}

			totalRemainingTea += std::max(0, totalBrought - totalConsumed);
		}
	}

	std::cout << totalRemainingTea << std::endl;
	return 0;
}
