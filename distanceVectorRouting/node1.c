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

int connectcosts1[4] = { 1,  0,  1, 999 };

struct distance_table 
{
  int costs[4][4];
} dt1;


/* students to write the following two routines, and maybe some others */


rtinit1(){

  // initialize distance table. 
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      dt1.costs[i][j] = 999; // initialzie the cost array to infinity
    }
  }

  // update the base cost of node 0
  dt1.costs[1][0] = 1; 
  dt1.costs[1][1] = 0;
  dt1.costs[1][2] = 1;
  dt1.costs[1][3] = 999;

  // call the print function for dt0
  printdt0(&dt0);

  // send minimual cost to bidirectional neighbors.
  struct rtpkt rtpkt1, rtpkt2;
  rtpkt1.sourceid = 1; 
  rtpkt1.destid = 0; 

  rtpkt2.sourceid = 1; 
  rtpkt2.destid = 2;

  // put the values into the mincost 
  for(int i = 0; i < 4; i++){
    rtpkt1.mincost[i] = dt1.costs[1][i]
    rtpkt2.mincost[i] = dt1.costs[1][i]

    //send the mincost using tolayer2
    tolayer2(rtpkt1)
    tolayer2(rtpkt2)
  }

}
  

}


rtupdate1(rcvdpkt) struct rtpkt *rcvdpkt;
  
{

  // first, check to see if the packet arrived at the right destination.
  if(rcvdpkt->destid != 1){
    return; 
  }

  sourceid = rcvdpkt->destid;

  // Now check if dt0 needs to be updated.
  for(int i = 0; i < 4; i++){
    if(dt1.costs[sourceid][i] > rcvdpkt->mincost[i]){
      dt1.costs[sourceid][i] = rcvdpkt->mincost[i];
  }
  

    //time to send minimual cost to directional neighbors 
  struct rtpkt rtpkt1, rtpkt2, rtpkt3;
  rtpkt1.sourceid = 1; 
  rtpkt1.destid = 0; 

  rtpkt2.sourceid = 1; 
  rtpkt2.destid = 2;

  // after the update send its new mincost.
  tolayer2(rtpkt1)
  tolayer2(rtpkt2)
}


printdt1(dtptr)
  struct distance_table *dtptr;
  
{
  printf("             via   \n");
  printf("   D1 |    0     2 \n");
  printf("  ----|-----------\n");
  printf("     0|  %3d   %3d\n",dtptr->costs[0][0], dtptr->costs[0][2]);
  printf("dest 2|  %3d   %3d\n",dtptr->costs[2][0], dtptr->costs[2][2]);
  printf("     3|  %3d   %3d\n",dtptr->costs[3][0], dtptr->costs[3][2]);

}



linkhandler1(linkid, newcost)   
int linkid, newcost;   
/* called when cost from 1 to linkid changes from current value to newcost*/
/* You can leave this routine empty if you're an undergrad. If you want */
/* to use this routine, you'll need to change the value of the LINKCHANGE */
/* constant definition in prog3.c from 0 to 1 */
	
{
}

