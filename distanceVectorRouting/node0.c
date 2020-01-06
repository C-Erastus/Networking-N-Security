#include <stdio.h>

extern struct rtpkt {
  int sourceid;       /* id of sending router sending this pkt */
  int destid;         /* id of router to which pkt being sent 
                         (must be an immediate neighbor) */
  int mincost[4];    /* min cost to node 0 ... 3 */
  };

extern int TRACE;
extern int YES;
extern int NO;

struct distance_table 
{
  int costs[4][4];
} dt0;


/* students to write the following two routines, and maybe some others */

void rtinit0(){

  // initialize distance table. 
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      dt0.costs[i][j] = 999; // initialzie the cost array to infinity
    }
  }

  // update the base cost of node 0
  dt0.costs[0][0] = 0; 
  dt0.costs[0][1] = 1;
  dt0.costs[0][2] = 3;
  dt0.costs[0][3] = 7;

  // call the print function for dt0
  printdt0(&dt0);

  // send minimual cost to bidirectional neighbors.
  struct rtpkt rtpkt1, rtpkt2, rtpkt3;
  rtpkt1.sourceid = 0; 
  rtpkt1.destid = 1; 

  rtpkt2.sourceid = 0; 
  rtpkt2.destid = 2;

  rtpkt3.sourceid = 0; 
  rtpkt3.destid = 1;

  // put the values into the mincost 
  for(int i = 0; i < 4; i++){
    rtpkt1.mincost[i] = dt0.costs[0][i]
    rtpkt2.mincost[i] = dt0.costs[0][i]
    rtpkt3.mincost[i] = dt0.costs[0][i]

    //send the mincost using tolayer2
    tolayer2(rtpkt1)
    tolayer2(rtpkt2)
    tolayer2(rtpkt3)
  }

}

void rtupdate0(rcvdpkt) struct rtpkt *rcvdpkt;{

  // first, check to see if the packet arrived at the right destination.
  if(rcvdpkt->destid != 0){
    return; 
  }

  sourceid = rcvdpkt->destid;

  // Now check if dt0 needs to be updated.
  for(int i = 0; i < 4; i++){
    if(dt0.costs[sourceid][i] > rcvdpkt->mincost[i]){
      dt0.costs[sourceid][i] = rcvdpkt->mincost[i];
    }
  }

  //time to send minimual cost to directional neighbors 
  struct rtpkt rtpkt1, rtpkt2, rtpkt3;
  rtpkt1.sourceid = 0; 
  rtpkt1.destid = 1; 

  rtpkt2.sourceid = 0; 
  rtpkt2.destid = 2;

  rtpkt3.sourceid = 0; 
  rtpkt3.destid = 1;

  // after the update send its new mincost.
  tolayer2(rtpkt1)
  tolayer2(rtpkt2)
  tolayer2(rtpkt3)
}

printdt0(dtptr)
  struct distance_table *dtptr;
  
{
  printf("                via     \n");
  printf("   D0 |    1     2    3 \n");
  printf("  ----|-----------------\n");
  printf("     1|  %3d   %3d   %3d\n",dtptr->costs[1][1],
	 dtptr->costs[1][2],dtptr->costs[1][3]);
  printf("dest 2|  %3d   %3d   %3d\n",dtptr->costs[2][1],
	 dtptr->costs[2][2],dtptr->costs[2][3]);
  printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][1],
	 dtptr->costs[3][2],dtptr->costs[3][3]);
}

linkhandler0(linkid, newcost)   
  int linkid, newcost;

/* called when cost from 0 to linkid changes from current value to newcost*/
/* You can leave this routine empty if you're an undergrad. If you want */
/* to use this routine, you'll need to change the value of the LINKCHANGE */
/* constant definition in prog3.c from 0 to 1 */
	
{
}
