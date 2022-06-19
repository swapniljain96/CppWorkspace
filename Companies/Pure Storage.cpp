// Binary buddy bitmap
//
// 0 -                [0](0)             parent i the left 2i+0: right: 2i+1;
//                ___/   \___
//               /           \           for child value i ;parent: floor((i-1)/2)
// 1 -        [0](0)         [0](1)
//           /   \           /   \                       0,1=0        floor(i/2);
//          /     \         /     \                      2,3=1      
// 2 -    [0](0)  [0](1)  "[0]"(2)  [1](3)               4,5=2   
//        / \     / \     / \     / \                    6,7=3
//       /   \   /   \   /   \   /   \
// 3 -  [0] [0] [0] [1] [1] [1] [1] [1]
//      (0) (1) (2) (3) (4) (5) (6) (7)     odd+len(even / odd) start=1 len=4   =3    4-1=3 
//              [0] [0] [0] [0]                                 start=2   len=4 =2    4-2=2
// [node value]                                                 start=1  len=5 = 3    4-2=2             
// (node index within level)                                        
        

[
    [0],
    [0, 1],
    [0, 0, 1, 1],
    [0, 0, 0, 1, 1, 1, 1, 1]
]

[
    [0, undef, undef, undef, ...],
    [0, 1, undef, undef, ]
    [0, 0 ,1,1,undef,undef,......]
    3 [0,0,0,1,1,1,1,1,undef,undef,......]
     0  1 2 3
]
BITS[3][5]= 4 / 5

//
// Parent value is 1 if and only if both children values are 1

// global HEIGHT
// global array BITS


// clear_bits(2, 4)

clear_bits(int start, int len)
{  
  for(int i=start;i<len;i++)
  {
      BITS[HEIGHT-1][i]=0
      
  }
  int parentStart=floor(start/2); 
  int parentEnd=floor(start+len-1/2); 
  int h=HEIGHT-2;    
  while(h>0)
  { for(int i=parentStart;i<=parentEnd;i++)
       {
          BITS[h][i]=0;
       }
    h--;
    parentStart=floor(parentStart/2);
    parentEnd=floor(parentEnd/2);
  }
    
}