package student;

import graph.*;

/**
 * An implementation of TraversalStrategy that follows the
 * breadth-first policy for finding new nodes.
 *
 * Created: Thu Apr 26 21:46:41 2007
 *
 * @author <a href="mailto:daniel.coore@uwimona.edu.jm">Daniel Coore</a>
 * @version 1.0
 */
public class BreadthFirst implements TraversalStrategy {

	Graph graph;		// graph being traversed
	Edge[] parent;		// array of traversal predecessors
	int[] priorities;		// assigned priorities
	int nextPriority;		// priority of next node

	public void init(Graph g, int startNode)
	{
    	graph = g;		// mainly for debugging
		initialiseArrays(g.size());
		parent[startNode] = null;	// no parent
		//COMPLETE HERE- FOR ONLINE ASSESSMENT
		//nextPriority = ??
    }


	protected void initialiseArrays(int n)
	{
		parent = new Edge[n];
		priorities = new int[n];

		for (int i = 0; i < n; i++)
		{
			parent[i] = null;	// no parent
			priorities[i] = -1;	// valid priorities are never negative
		}
	}

    public double computePriority(Edge edge) {
		int node = edge.getDest();
		System.out.println("node is " + node + "; priorities[node] is "
			  + priorities[node] + "; & nextpriority is " + nextPriority);
		if (priorities[node] < 0)
		{
			priorities[node] = nextPriority;
			//COMPLETE HERE- FOR ONLINE ASSESSMENT
			//nextPriority = ??

		}
		return (double) priorities[node];
	}

    public void discover(double priority, Edge nbrInfo) {
    }

    public void update(double priority, Edge nbrInfo) {
    }

    public void noupdate(double priority, Edge nbrInfo) {
    }

    public void complete(double priority, Edge nbrInfo) {
    }

    public Class getCCManagerClass() {
	return MyCCManager.class;
    }
}
