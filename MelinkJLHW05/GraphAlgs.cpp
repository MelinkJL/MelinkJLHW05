/**
* Credit to Sam Wolf and Jake Gregg for overall struture and functionality of this algorithm.
*/

#include "GraphAlgs.h"
#include <algorithm>

// Credit to my high school java instructor for this method (calculating the factorial of a number using recursion).
int factorial(int x) 
{	
	if (x == 1) 
	{		
		return 1;
	}	
	else 
	{		
		return factorial(x-1)*x;	
	}
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	std::vector<NodeID> currentPath;
	std::vector<NodeID> shortestPath;
	EdgeWeight weight = 0;
	EdgeWeight bestWeight = DBL_MAX;
	std::list<NWPair>::iterator it;

	for (int i = 0; i < (*G).size(); i++)
	{
		currentPath.push_back(i);
	}
	int currentSize = (*G).size();

	for (int i = 0; i < factorial(currentSize - 1); i++) 
	{		
		weight = (*G).weight(0, currentPath[0]);
		for (int j = 0; j < currentSize - 1; j++) 
		{			
			if (weight > bestWeight)
			{
				break;
			}
			else 
			{				
				if (j == currentSize - 2)
				{
					weight += (*G).weight(0, currentPath.at(j));
				}				
				else
				{
					weight += (*G).weight(currentPath.at(j+1), currentPath.at(j));
				}		
			}		
			
			if (weight < bestWeight) 
			{			
				bestWeight = weight;
				shortestPath = currentPath;		
			}		
			std::next_permutation(currentPath.begin(), currentPath.end());
		}	
		shortestPath.insert(shortestPath.begin(), 0);
		return std::make_pair(shortestPath, bestWeight);
	}
}