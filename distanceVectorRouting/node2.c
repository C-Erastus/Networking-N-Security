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
} dt2;


/* students to write the following two routines, and maybe some others */

void rtinit2(){

  // initialize distance table. 
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      dt0.costs[i][j] = 999; // initialzie the cost array to infinity
    }
  }

  // update the base cost of node 0
  dt2.costs[2][0] = 3; 
  dt2.costs[2][1] = 1;
  dt2.costs[2][2] = 0;
  dt2.costs[2][3] = 2;

  // call the print function for dt0
  printdt0(&dt2);

  // send minimual cost to bidirectional neighbors.
  struct rtpkt rtpkt1, rtpkt2, rtpkt3;
  rtpkt1.sourceid = 2; 
  rtpkt1.destid = 0; 

  rtpkt2.sourceid = 2; 
  rtpkt2.destid = 1;

  rtpkt3.sourceid = 2; 
  rtpkt3.destid = 3;

  // put the values into the mincost 
  for(int i = 0; i < 4; i++){
    rtpkt1.mincost[i] = dt2.costs[2][i]
    rtpkt2.mincost[i] = dt2.costs[2][i]
    rtpkt3.mincost[i] = dt2.costs[2][i]

    //send the mincost using tolayer2
    tolayer2(rtpkt1)
    tolayer2(rtpkt2)
    tolayer2(rtpkt3)
  }

}
  
}


void rtupdate2(rcvdpkt) struct rtpkt *rcvdpkt;
  
{
  // first, check to see if the packet arrived at the right destination.
  if(rcvdpkt->destid != 2 ){
    return; 
  }

  sourceid = rcvdpkt->destid;

  // Now check if dt0 needs to be updated.
  for(int i = 0; i < 4; i++){
    if(dt2.costs[sourceid][i] > rcvdpkt->mincost[i]){
      dt2.costs[sourceid][i] = rcvdpkt->mincost[i];
  }
  

    //time to send minimual cost to directional neighbors 
  struct rtpkt rtpkt1, rtpkt2, rtpkt3;
  rtpkt1.sourceid = 2; 
  rtpkt1.destid = 1; 

  rtpkt2.sourceid = 2; 
  rtpkt2.destid = 3;

  rtpkt3.sourceid = 2; 
  rtpkt3.destid = 0;

  // after the update send its new mincost.
  tolayer2(rtpkt1)
  tolayer2(rtpkt2)
  tolayer2(rtpkt3)

}


printdt2(dtptr)
  struct distance_table *dtptr;
  
{
  printf("                via     \n");
  printf("   D2 |    0     1    3 \n");
  printf("  ----|-----------------\n");
  printf("     0|  %3d   %3d   %3d\n",dtptr->costs[0][0],
	 dtptr->costs[0][1],dtptr->costs[0][3]);
  printf("dest 1|  %3d   %3d   %3d\n",dtptr->costs[1][0],
	 dtptr->costs[1][1],dtptr->costs[1][3]);
  printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][0],
	 dtptr->costs[3][1],dtptr->costs[3][3]);
}






