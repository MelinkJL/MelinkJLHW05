#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(int numNodes) 
{	
	edgeList.resize(numNodes);	
	num_edges = 0;
}

ListGraph::~ListGraph()
{

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	EList::const_iterator it;

	bool switchOn = false;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++) 
	{
		NWPair nodePair = (*it);
		if(nodePair.first == v)
		{
			nodePair.second = weight;
			switchOn = true;
		}
	}
	if(switchOn) 
	{
		for(it = edgeList[v].begin(); it != edgeList[v].end(); it++)
		{
			NWPair nodePair = (*it);
			if(nodePair.first == u) 
			{
				nodePair.second = weight;
				num_edges++;
				return;
			}
		}
	}

	NWPair nodePair = std::make_pair(v,weight);	
	edgeList[u].push_back(nodePair);	
	nodePair.first = u;		
	edgeList[v].push_back(nodePair);	
	num_edges++;
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const 
{	
	EList::const_iterator it;	
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++) 
	{		
		NWPair edge = (*it);
		if(edge.first == v)
		{			
			return edge.second;
		}	
	}	
	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const 
{	
	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const 
{	
	return edgeList[u].size();
}

unsigned ListGraph::size() const 
{	
	return edgeList.size();
}

unsigned ListGraph::numEdges() const
{	
	return num_edges;
}