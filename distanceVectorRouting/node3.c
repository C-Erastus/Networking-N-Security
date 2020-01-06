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
} dt3;

/* students to write the following two routines, and maybe some others */

void rtinit3(){

  // initialize distance table. 
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      dt3.costs[i][j] = 999; // initialzie the cost array to infinity
    }
  }

  // update the base cost of node 0
  dt3.costs[3][0] = 7; 
  dt3.costs[3][1] = 999;
  dt3.costs[3][2] = 3;
  dt3.costs[3][3] = 0;

  // call the print function for dt0
  printdt0(&dt3);

  // send minimual cost to bidirectional neighbors.
  struct rtpkt rtpkt1, rtpkt2;
  rtpkt1.sourceid = 3; 
  rtpkt1.destid = 0; 

  rtpkt2.sourceid = 3; 
  rtpkt2.destid = 2;


  // put the values into the mincost 
  for(int i = 0; i < 4; i++){
    rtpkt1.mincost[i] = dt3.costs[3][i]
    rtpkt2.mincost[i] = dt3.costs[3][i]

    //send the mincost using tolayer2
    tolayer2(rtpkt1)
    tolayer2(rtpkt2)
  }

}
  
}


void rtupdate3(rcvdpkt) struct rtpkt *rcvdpkt;{

  // first, check to see if the packet arrived at the right destination.
  if(rcvdpkt->destid != 3){
    return; 
  }

  sourceid = rcvdpkt->destid;

  // Now check if dt0 needs to be updated.
  for(int i = 0; i < 4; i++){
    if(dt3.costs[sourceid][i] > rcvdpkt->mincost[i]){
      dt3.costs[sourceid][i] = rcvdpkt->mincost[i];
  }
  

    //time to send minimual cost to directional neighbors 
  struct rtpkt rtpkt1, rtpkt2, rtpkt3;
 
  rtpkt2.sourceid = 3; 
  rtpkt2.destid = 2;

  rtpkt3.sourceid = 3; 
  rtpkt3.destid = 0;

  // after the update send its new mincost.
  tolayer2(rtpkt1)
  tolayer2(rtpkt2)

}


printdt3(dtptr) struct distance_table *dtptr; {
  printf("             via     \n");
  printf("   D3 |    0     2 \n");
  printf("  ----|-----------\n");
  printf("     0|  %3d   %3d\n",dtptr->costs[0][0], dtptr->costs[0][2]);
  printf("dest 1|  %3d   %3d\n",dtptr->costs[1][0], dtptr->costs[1][2]);
  printf("     2|  %3d   %3d\n",dtptr->costs[2][0], dtptr->costs[2][2]);

}






