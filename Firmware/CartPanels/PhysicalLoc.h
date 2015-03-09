#define RIGHT 1
#define LEFT  2
#define FRONT 3
//DON'T FORGET USBCCFG.C
#define SIDE LEFT
	 
rom unsigned char ChanLength[8] =  
                                 #if SIDE == LEFT
                                 
	                               {48, //0
                                    42, //1
                                    42, //2
                                    0, //3
                                    0, //4
                                    42, //5
                                    48, //6
                                    48};//7
                                    
                                 #elif SIDE == RIGHT
                                   {72, //0
                                    48, //1
                                    36, //2
                                    42, //3
                                    36, //4
                                    42, //5
                                    0, //6
                                    0};//7
                                  #elif SIDE == FRONT
                                   {24, //0
                                    0, //1
                                    30, //2
                                    0, //3 //PANEL
                                    6, //4
                                    24, //5
                                    0, //6
                                    6};//7
                                  #endif
                                   
 
    #define EMPTY 254
	 #define END   255
	               //[8 output channels][ 60 bits to channel][x,y]
	 rom char PhysLoc[8                ][ 73                ][2] = 
	                                                               #if SIDE == LEFT
	                                                               
	                                                                {{{EMPTY,EMPTY}, // Channel 0. bit 0
	                                                                  { 3,13}, // Channel 0. bit 1
	                                                                  { 4,13}, // Channel 0. bit 2
	                                                                  { 4,12}, // Channel 0. bit 3
	                                                                  { 3,12}, // Channel 0. bit 4
	                                                                  { 2,12}, // Channel 0. bit 5
	                                                                  { 5,13}, // Channel 0. bit 6
	                                                                  { 6,13}, // Channel 0. bit 7
	                                                                  { 7,13}, // Channel 0. bit 8
	                                                                  { 7,12}, // Channel 0. bit 9
	                                                                  { 6,12}, // Channel 0. bit 10
	                                                                  { 5,12}, // Channel 0. bit 11
	                                                                  { 8,13}, // Channel 0. bit 12
	                                                                  { 9,13}, // Channel 0. bit 13
	                                                                  {10,13}, // Channel 0. bit 14
	                                                                  {10,12}, // Channel 0. bit 15
	                                                                  { 9,12}, // Channel 0. bit 16
	                                                                  { 8,12}, // Channel 0. bit 17
	                                                                  {11,12}, // Channel 0. bit 18
	                                                                  {12,12}, // Channel 0. bit 19                                                             {0,0} // 0
	                                                                  {13,12}, // Channel 0. bit 20
	                                                                  {13,11}, // Channel 0. bit 21
	                                                                  {12,11}, // Channel 0. bit 22
	                                                                  {11,11}, // Channel 0. bit 23
	                                                                  {14,12}, // Channel 0. bit 24
	                                                                  {15,12}, // Channel 0. bit 25
	                                                                  {16,12}, // Channel 0. bit 26
	                                                                  {16,11}, // Channel 0. bit 27
	                                                                  {15,11}, // Channel 0. bit 28                                                            {0,0} // 0
	                                                                  {14,11}, // Channel 0. bit 29
	                                                                  {17,12}, // Channel 0. bit 30
	                                                                  {18,12}, // Channel 0. bit 31
	                                                                  {19,12}, // Channel 0. bit 32
	                                                                  {19,11}, // Channel 0. bit 33
	                                                                  {18,11}, // Channel 0. bit 34
	                                                                  {17,11}, // Channel 0. bit 35
	                                                                  {20,12}, // Channel 0. bit 36
	                                                                  {21,12}, // Channel 0. bit 37                                                           {0,0} // 0
	                                                                  {22,12}, // Channel 0. bit 38
	                                                                  {22,11}, // Channel 0. bit 39
	                                                                  {21,11}, // Channel 0. bit 40
	                                                                  {20,11}, // Channel 0. bit 41
	                                                                  {23,12}, // Channel 0. bit 42
	                                                                  {24,12}, // Channel 0. bit 43
	                                                                  {25,12}, // Channel 0. bit 44
	                                                                  {25,11}, // Channel 0. bit 45
	                                                                  {24,11}, // Channel 0. bit 46                                                            {0,0} // 0
	                                                                  {23,11}, // Channel 0. bit 47
	                                                                  {END,END}, // Channel 0. bit 48
	                                                                  {0,0}, // Channel 0. bit 49
	                                                                  {0,0}, // Channel 0. bit 50
	                                                                  {0,0}, // Channel 0. bit 51
	                                                                  {0,0}, // Channel 0. bit 52
	                                                                  {0,0}, // Channel 0. bit 53
	                                                                  {0,0}, // Channel 0. bit 54
	                                                                  {0,0}, // Channel 0. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 0. bit 56
	                                                                  {0,0}, // Channel 0. bit 57
	                                                                  {0,0}, // Channel 0. bit 58
	                                                                  {0,0}, // Channel 0. bit 59
	                                                                  {0,0}, // Channel 0. bit 60
	                                                                  {0,0}, // Channel 0. bit 61
	                                                                  {0,0}, // Channel 0. bit 62
	                                                                  {0,0}, // Channel 0. bit 63
	                                                                  {0,0}, // Channel 0. bit 64
	                                                                  {0,0}, // Channel 0. bit 65
	                                                                  {0,0}, // Channel 0. bit 66
	                                                                  {0,0}, // Channel 0. bit 67
	                                                                  {0,0}, // Channel 0. bit 68
	                                                                  {0,0}, // Channel 0. bit 69
	                                                                  {0,0}, // Channel 0. bit 70
	                                                                  {0,0}, // Channel 0. bit 71
	                                                                  {0,0}},// Channel 0. bit 72
	                                                                  
	                                                                  {{1,5}, // Channel 1. bit 0
	                                                                  {2,5}, // Channel 1. bit 1
	                                                                  {3,5}, // Channel 1. bit 2
	                                                                  {3,4}, // Channel 1. bit 3
	                                                                  {2,4}, // Channel 1. bit 4
	                                                                  {1,4}, // Channel 1. bit 5
	                                                                  {4,5}, // Channel 1. bit 6
	                                                                  {5,5}, // Channel 1. bit 7
	                                                                  {6,5}, // Channel 1. bit 8
	                                                                  {6,4}, // Channel 1. bit 9
	                                                                  {5,4}, // Channel 1. bit 10
	                                                                  {4,4}, // Channel 1. bit 11
	                                                                  {7,5}, // Channel 1. bit 12
	                                                                  {8,5}, // Channel 1. bit 13
	                                                                  {9,5}, // Channel 1. bit 14
	                                                                  {9,4}, // Channel 1. bit 15
	                                                                  {8,4}, // Channel 1. bit 16
	                                                                  {7,4}, // Channel 1. bit 17
	                                                                  {10,6}, // Channel 1. bit 18
	                                                                  {11,6}, // Channel 1. bit 19                                                             {0,0} // 0
	                                                                  {12,6}, // Channel 1. bit 20
	                                                                  {12,5}, // Channel 1. bit 21
	                                                                  {11,5}, // Channel 1. bit 22
	                                                                  {10,5}, // Channel 1. bit 23
	                                                                  {13,6}, // Channel 1. bit 24
	                                                                  {14,6}, // Channel 1. bit 25
	                                                                  {15,6}, // Channel 1. bit 26
	                                                                  {15,5}, // Channel 1. bit 27
	                                                                  {14,5}, // Channel 1. bit 28                                                            {0,0} // 0
	                                                                  {13,5}, // Channel 1. bit 29
	                                                                  {16,6}, // Channel 1. bit 30
	                                                                  {17,6}, // Channel 1. bit 31
	                                                                  {18,6}, // Channel 1. bit 32
	                                                                  {18,5}, // Channel 1. bit 33
	                                                                  {17,5}, // Channel 1. bit 34
	                                                                  {16,5}, // Channel 1. bit 35
	                                                                  {19,6}, // Channel 1. bit 36
	                                                                  {20,6}, // Channel 1. bit 37                                                           {0,0} // 0
	                                                                  {21,6}, // Channel 1. bit 38
	                                                                  {21,5}, // Channel 1. bit 39
	                                                                  {20,5}, // Channel 1. bit 40
	                                                                  {19,5}, // Channel 1. bit 41
	                                                                  {END,END}, // Channel 1. bit 42
	                                                                  {0,0}, // Channel 1. bit 43
	                                                                  {0,0}, // Channel 1. bit 44
	                                                                  {0,0}, // Channel 1. bit 45
	                                                                  {0,0}, // Channel 1. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 1. bit 47
	                                                                  {0,0}, // Channel 1. bit 48
	                                                                  {0,0}, // Channel 1. bit 49
	                                                                  {0,0}, // Channel 1. bit 50
	                                                                  {0,0}, // Channel 1. bit 51
	                                                                  {0,0}, // Channel 1. bit 52
	                                                                  {0,0}, // Channel 1. bit 53
	                                                                  {0,0}, // Channel 1. bit 54
	                                                                  {0,0}, // Channel 1. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 1. bit 56
	                                                                  {0,0}, // Channel 1. bit 57
	                                                                  {0,0}, // Channel 1. bit 58
	                                                                  {0,0}, // Channel 1. bit 59
	                                                                  {0,0}, // Channel 1. bit 60
	                                                                  {0,0}, // Channel 1. bit 61
	                                                                  {0,0}, // Channel 1. bit 62
	                                                                  {0,0}, // Channel 1. bit 63
	                                                                  {0,0}, // Channel 1. bit 64
	                                                                  {0,0}, // Channel 1. bit 65
	                                                                  {0,0}, // Channel 1. bit 66
	                                                                  {0,0}, // Channel 1. bit 67
	                                                                  {0,0}, // Channel 1. bit 68
	                                                                  {0,0}, // Channel 1. bit 69
	                                                                  {0,0}, // Channel 1. bit 70
	                                                                  {0,0}, // Channel 1. bit 71
	                                                                  {0,0}},// Channel 1. bit 72
	                                                                  
	                                                                  {{EMPTY,EMPTY}, // Channel 2. bit 0
	                                                                  {9,10}, // Channel 2. bit  1
	                                                                  {8,10}, // Channel 2. bit  2
	                                                                  {8,1}, // Channel 2. bit  3
	                                                                  {9,11}, // Channel 2. bit  4
	                                                                  {10,11}, // Channel 2. bit  5
	                                                                  {EMPTY,EMPTY}, // Channel 2. bit  6
	                                                                  {8,9}, // Channel 2. bit  7
	                                                                  {9,9}, // Channel 2. bit  8
	                                                                  {9,8}, // Channel 2. bit  9
	                                                                  {8,8}, // Channel 2. bit  10
	                                                                  {7,8}, // Channel 2. bit  11
	                                                                  {10,10}, // Channel 2. bit  12
	                                                                  {11,10}, // Channel 2. bit  13
	                                                                  {12,10}, // Channel 2. bit  14
	                                                                  {12,9}, // Channel 2. bit  15
	                                                                  {11,9}, // Channel 2. bit  16
	                                                                  {10,9}, // Channel 2. bit  17
	                                                                  {13,10}, // Channel 2. bit  18
	                                                                  {14,10}, // Channel 2. bit  19                                                             {0,0} // 0
	                                                                  {15,10}, // Channel 2. bit  20
	                                                                  {15,9}, // Channel 2. bit  21
	                                                                  {14,9}, // Channel 2. bit  22
	                                                                  {13,9}, // Channel 2. bit  23
	                                                                  {16,10}, // Channel 2. bit  24
	                                                                  {17,10}, // Channel 2. bit  25
	                                                                  {18,10}, // Channel 2. bit  26
	                                                                  {18,9}, // Channel 2. bit  27
	                                                                  {17,9}, // Channel 2. bit  28                                                            {0,0} // 0
	                                                                  {16,9}, // Channel 2. bit  29
	                                                                  {19,10}, // Channel 2. bit  30
	                                                                  {20,10}, // Channel 2. bit  31
	                                                                  {21,10}, // Channel 2. bit  32
	                                                                  {21,9}, // Channel 2. bit  33
	                                                                  {20,9}, // Channel 2. bit  34
	                                                                  {19,9}, // Channel 2. bit  35
	                                                                  {22,10}, // Channel 2. bit  36
	                                                                  {23,10}, // Channel 2. bit  37                                                           {0,0} // 0
	                                                                  {24,10}, // Channel 2. bit  38
	                                                                  {24,9}, // Channel 2. bit  39
	                                                                  {23,9}, // Channel 2. bit  40
	                                                                  {22,9}, // Channel 2. bit  41
	                                                                  {END,END}, // Channel 2. bit  42
	                                                                  {0,0}, // Channel 2. bit  43
	                                                                  {0,0}, // Channel 2. bit  44
	                                                                  {0,0}, // Channel 2. bit  45
	                                                                  {0,0}, // Channel 2. bit  46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 2. bit  47
	                                                                  {0,0}, // Channel 2. bit  48
	                                                                  {0,0}, // Channel 2. bit  49
	                                                                  {0,0}, // Channel 2. bit  50
	                                                                  {0,0}, // Channel 2. bit  51
	                                                                  {0,0}, // Channel 2. bit  52
	                                                                  {0,0}, // Channel 2. bit  53
	                                                                  {0,0}, // Channel 2. bit  54
	                                                                  {0,0}, // Channel 2. bit  55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 2. bit  56
	                                                                  {0,0}, // Channel 2. bit  57
	                                                                  {0,0}, // Channel 2. bit  58
	                                                                  {0,0}, // Channel 2. bit  59
	                                                                  {0,0}, // Channel 2. bit  60
	                                                                  {0,0}, // Channel 2. bit  61
	                                                                  {0,0}, // Channel 2. bit  62
	                                                                  {0,0}, // Channel 2. bit  63
	                                                                  {0,0}, // Channel 2. bit  64
	                                                                  {0,0}, // Channel 2. bit  65
	                                                                  {0,0}, // Channel 2. bit  66
	                                                                  {0,0}, // Channel 2. bit  67
	                                                                  {0,0}, // Channel 2. bit  68
	                                                                  {0,0}, // Channel 2. bit  69
	                                                                  {0,0}, // Channel 2. bit  70
	                                                                  {0,0}, // Channel 2. bit  71
	                                                                  {0,0}},// Channel 2. bit  72
	                                                                  
	                                                                  {{END,END}, // Channel 3. bit  0
	                                                                  {0,0}, // Channel 3. bit 1
	                                                                  {0,0}, // Channel 3. bit 2
	                                                                  {0,0}, // Channel 3. bit 3
	                                                                  {0,0}, // Channel 3. bit 4
	                                                                  {0,0}, // Channel 3. bit 5
	                                                                  {0,0}, // Channel 3. bit 6
	                                                                  {0,0}, // Channel 3. bit 7
	                                                                  {0,0}, // Channel 3. bit 8
	                                                                  {0,0}, // Channel 3. bit 9
	                                                                  {0,0}, // Channel 3. bit 10
	                                                                  {0,0}, // Channel 3. bit 11
	                                                                  {0,0}, // Channel 3. bit 12
	                                                                  {0,0}, // Channel 3. bit 13
	                                                                  {0,0}, // Channel 3. bit 14
	                                                                  {0,0}, // Channel 3. bit 15
	                                                                  {0,0}, // Channel 3. bit 16
	                                                                  {0,0}, // Channel 3. bit 17
	                                                                  {0,0}, // Channel 3. bit 18
	                                                                  {0,0}, // Channel 3. bit 19                                                             {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 20
	                                                                  {0,0}, // Channel 3. bit 21
	                                                                  {0,0}, // Channel 3. bit 22
	                                                                  {0,0}, // Channel 3. bit 23
	                                                                  {0,0}, // Channel 3. bit 24
	                                                                  {0,0}, // Channel 3. bit 25
	                                                                  {0,0}, // Channel 3. bit 26
	                                                                  {0,0}, // Channel 3. bit 27
	                                                                  {0,0}, // Channel 3. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 29
	                                                                  {0,0}, // Channel 3. bit 30
	                                                                  {0,0}, // Channel 3. bit 31
	                                                                  {0,0}, // Channel 3. bit 32
	                                                                  {0,0}, // Channel 3. bit 33
	                                                                  {0,0}, // Channel 3. bit 34
	                                                                  {0,0}, // Channel 3. bit 35
	                                                                  {0,0}, // Channel 3. bit 36
	                                                                  {0,0}, // Channel 3. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 38
	                                                                  {0,0}, // Channel 3. bit 39
	                                                                  {0,0}, // Channel 3. bit 40
	                                                                  {0,0}, // Channel 3. bit 41
	                                                                  {0,0}, // Channel 3. bit 42
	                                                                  {0,0}, // Channel 3. bit 43
	                                                                  {0,0}, // Channel 3. bit 44
	                                                                  {0,0}, // Channel 3. bit 45
	                                                                  {0,0}, // Channel 3. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 47
	                                                                  {0,0}, // Channel 3. bit 48
	                                                                  {0,0}, // Channel 3. bit 49
	                                                                  {0,0}, // Channel 3. bit 50
	                                                                  {0,0}, // Channel 3. bit 51
	                                                                  {0,0}, // Channel 3. bit 52
	                                                                  {0,0}, // Channel 3. bit 53
	                                                                  {0,0}, // Channel 3. bit 54
	                                                                  {0,0}, // Channel 3. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 56
	                                                                  {0,0}, // Channel 3. bit 57
	                                                                  {0,0}, // Channel 3. bit 58
	                                                                  {0,0}, // Channel 3. bit 59
	                                                                  {0,0}, // Channel 3. bit 60
	                                                                  {0,0}, // Channel 3. bit 61
	                                                                  {0,0}, // Channel 3. bit 62
	                                                                  {0,0}, // Channel 3. bit 63
	                                                                  {0,0}, // Channel 3. bit 64
	                                                                  {0,0}, // Channel 3. bit 65
	                                                                  {0,0}, // Channel 3. bit 66
	                                                                  {0,0}, // Channel 3. bit 67
	                                                                  {0,0}, // Channel 3. bit 68
	                                                                  {0,0}, // Channel 3. bit 69
	                                                                  {0,0}, // Channel 3. bit 70
	                                                                  {0,0}, // Channel 3. bit 71
	                                                                  {0,0}},// Channel 3. bit 72
	                                                                  
	                                                                  {{END,END},// Channel 4. bit 0
	                                                                  {0,0}, // Channel 4. bit 1
	                                                                  {0,0}, // Channel 4. bit 2
	                                                                  {0,0}, // Channel 4. bit 3
	                                                                  {0,0}, // Channel 4. bit 4
	                                                                  {0,0}, // Channel 4. bit 5
	                                                                  {0,0}, // Channel 4. bit 6
	                                                                  {0,0}, // Channel 4. bit 7
	                                                                  {0,0}, // Channel 4. bit 8
	                                                                  {0,0}, // Channel 4. bit 9
	                                                                  {0,0}, // Channel 4. bit 10
	                                                                  {0,0}, // Channel 4. bit 11
	                                                                  {0,0}, // Channel 4. bit 12
	                                                                  {0,0}, // Channel 4. bit 13
	                                                                  {0,0}, // Channel 4. bit 14
	                                                                  {0,0}, // Channel 4. bit 15
	                                                                  {0,0}, // Channel 4. bit 16
	                                                                  {0,0}, // Channel 4. bit 17
	                                                                  {0,0}, // Channel 4. bit 18
	                                                                  {0,0}, // Channel 4. bit 19                                                             {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 20
	                                                                  {0,0}, // Channel 4. bit 21
	                                                                  {0,0}, // Channel 4. bit 22
	                                                                  {0,0}, // Channel 4. bit 23
	                                                                  {0,0}, // Channel 4. bit 24
	                                                                  {0,0}, // Channel 4. bit 25
	                                                                  {0,0}, // Channel 4. bit 26
	                                                                  {0,0}, // Channel 4. bit 27
	                                                                  {0,0}, // Channel 4. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 29
	                                                                  {0,0}, // Channel 4. bit 30
	                                                                  {0,0}, // Channel 4. bit 31
	                                                                  {0,0}, // Channel 4. bit 32
	                                                                  {0,0}, // Channel 4. bit 33
	                                                                  {0,0}, // Channel 4. bit 34
	                                                                  {0,0}, // Channel 4. bit 35
	                                                                  {0,0}, // Channel 4. bit 36
	                                                                  {0,0}, // Channel 4. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 38
	                                                                  {0,0}, // Channel 4. bit 39
	                                                                  {0,0}, // Channel 4. bit 40
	                                                                  {0,0}, // Channel 4. bit 41
	                                                                  {0,0}, // Channel 4. bit 42
	                                                                  {0,0}, // Channel 4. bit 43
	                                                                  {0,0}, // Channel 4. bit 44
	                                                                  {0,0}, // Channel 4. bit 45
	                                                                  {0,0}, // Channel 4. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 47
	                                                                  {0,0}, // Channel 4. bit 48
	                                                                  {0,0}, // Channel 4. bit 49
	                                                                  {0,0}, // Channel 4. bit 50
	                                                                  {0,0}, // Channel 4. bit 51
	                                                                  {0,0}, // Channel 4. bit 52
	                                                                  {0,0}, // Channel 4. bit 53
	                                                                  {0,0}, // Channel 4. bit 54
	                                                                  {0,0}, // Channel 4. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 56
	                                                                  {0,0}, // Channel 4. bit 57
	                                                                  {0,0}, // Channel 4. bit 58
	                                                                  {0,0}, // Channel 4. bit 59
	                                                                  {0,0}, // Channel 4. bit 60
	                                                                  {0,0}, // Channel 4. bit 61
	                                                                  {0,0}, // Channel 4. bit 62
	                                                                  {0,0}, // Channel 4. bit 63
	                                                                  {0,0}, // Channel 4. bit 64
	                                                                  {0,0}, // Channel 4. bit 65
	                                                                  {0,0}, // Channel 4. bit 66
	                                                                  {0,0}, // Channel 4. bit 67
	                                                                  {0,0}, // Channel 4. bit 68
	                                                                  {0,0}, // Channel 4. bit 69
	                                                                  {0,0}, // Channel 4. bit 70
	                                                                  {0,0}, // Channel 4. bit 71
	                                                                  {0,0}},// Channel 4. bit 72
	                                                                  
	                                                                  {{0,3},// Channel 5. bit 0
	                                                                  {1,3}, // Channel 5. bit 1
	                                                                  {2,3}, // Channel 5. bit 2
	                                                                  {2,2}, // Channel 5. bit 3
	                                                                  {1,2}, // Channel 5. bit 4
	                                                                  {0,2}, // Channel 5. bit 5
	                                                                  {3,3}, // Channel 5. bit 6
	                                                                  {4,3}, // Channel 5. bit 7
	                                                                  {5,3}, // Channel 5. bit 8
	                                                                  {5,2}, // Channel 5. bit 9
	                                                                  {4,2}, // Channel 5. bit 10
	                                                                  {3,2}, // Channel 5. bit 11
	                                                                  {6,3}, // Channel 5. bit 12
	                                                                  {7,3}, // Channel 5. bit 13
	                                                                  {8,3}, // Channel 5. bit 14
	                                                                  {8,2}, // Channel 5. bit 15
	                                                                  {7,2}, // Channel 5. bit 16
	                                                                  {6,2}, // Channel 5. bit 17
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 18
	                                                                  {10,4}, // Channel 5. bit 19                                                             {0,0} // 0
	                                                                  {11,4}, // Channel 5. bit 20
	                                                                  {11,3}, // Channel 5. bit 21
	                                                                  {10,3}, // Channel 5. bit 22
	                                                                  {9,3}, // Channel 5. bit 23
	                                                                  {12,4}, // Channel 5. bit 24
	                                                                  {13,4}, // Channel 5. bit 25
	                                                                  {14,4}, // Channel 5. bit 26
	                                                                  {14,3}, // Channel 5. bit 27
	                                                                  {13,3}, // Channel 5. bit 28                                                            {0,0} // 0
	                                                                  {12,3}, // Channel 5. bit 29
	                                                                  {15,4}, // Channel 5. bit 30
	                                                                  {16,4}, // Channel 5. bit 31
	                                                                  {17,4}, // Channel 5. bit 32
	                                                                  {17,3}, // Channel 5. bit 33
	                                                                  {16,3}, // Channel 5. bit 34
	                                                                  {15,3}, // Channel 5. bit 35
	                                                                  {18,4}, // Channel 5. bit 36
	                                                                  {19,4}, // Channel 5. bit 37                                                           {0,0} // 0
	                                                                  {20,4}, // Channel 5. bit 38
	                                                                  {20,3}, // Channel 5. bit 39
	                                                                  {19,3}, // Channel 5. bit 40
	                                                                  {18,3}, // Channel 5. bit 41
	                                                                  {END,END}, // Channel 5. bit 42
	                                                                  {0,0}, // Channel 5. bit 43
	                                                                  {0,0}, // Channel 5. bit 44
	                                                                  {0,0}, // Channel 5. bit 45
	                                                                  {0,0}, // Channel 5. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 5. bit 47
	                                                                  {0,0}, // Channel 5. bit 48
	                                                                  {0,0}, // Channel 5. bit 49
	                                                                  {0,0}, // Channel 5. bit 50
	                                                                  {0,0}, // Channel 5. bit 51
	                                                                  {0,0}, // Channel 5. bit 52
	                                                                  {0,0}, // Channel 5. bit 53
	                                                                  {0,0}, // Channel 5. bit 54
	                                                                  {0,0}, // Channel 5. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 5. bit 56
	                                                                  {0,0}, // Channel 5. bit 57
	                                                                  {0,0}, // Channel 5. bit 58
	                                                                  {0,0}, // Channel 5. bit 59
	                                                                  {0,0}, // Channel 5. bit 60
	                                                                  {0,0}, // Channel 5. bit 61
	                                                                  {0,0}, // Channel 5. bit 62
	                                                                  {0,0}, // Channel 5. bit 63
	                                                                  {0,0}, // Channel 5. bit 64
	                                                                  {0,0}, // Channel 5. bit 65
	                                                                  {0,0}, // Channel 5. bit 66
	                                                                  {0,0}, // Channel 5. bit 67
	                                                                  {0,0}, // Channel 5. bit 68
	                                                                  {0,0}, // Channel 5. bit 69
	                                                                  {0,0}, // Channel 5. bit 70
	                                                                  {0,0}, // Channel 5. bit 71
	                                                                  {0,0}},// Channel 5. bit 72
	                                                                  
	                                                                  {{1,7},// Channel 6. bit 0
	                                                                  {2,7}, // Channel 6. bit 1
	                                                                  {3,7}, // Channel 6. bit 2
	                                                                  {3,6}, // Channel 6. bit 3
	                                                                  {2,6}, // Channel 6. bit 4
	                                                                  {1,6}, // Channel 6. bit 5
	                                                                  {4,7}, // Channel 6. bit 6
	                                                                  {5,7}, // Channel 6. bit 7
	                                                                  {6,7}, // Channel 6. bit 8
	                                                                  {6,6}, // Channel 6. bit 9
	                                                                  {5,6}, // Channel 6. bit 10
	                                                                  {4,6}, // Channel 6. bit 11
	                                                                  {7,7}, // Channel 6. bit 12
	                                                                  {8,7}, // Channel 6. bit 13
	                                                                  {9,7}, // Channel 6. bit 14
	                                                                  {9,6}, // Channel 6. bit 15
	                                                                  {8,6}, // Channel 6. bit 16
	                                                                  {7,6}, // Channel 6. bit 17
	                                                                  {10,8}, // Channel 6. bit 18
	                                                                  {11,8}, // Channel 6. bit 19                                                             {0,0} // 0
	                                                                  {12,8}, // Channel 6. bit 20
	                                                                  {12,7}, // Channel 6. bit 21
	                                                                  {11,7}, // Channel 6. bit 22
	                                                                  {10,7}, // Channel 6. bit 23
	                                                                  {13,8}, // Channel 6. bit 24
	                                                                  {14,8}, // Channel 6. bit 25
	                                                                  {15,8}, // Channel 6. bit 26
	                                                                  {15,7}, // Channel 6. bit 27
	                                                                  {14,7}, // Channel 6. bit 28                                                            {0,0} // 0
	                                                                  {13,7}, // Channel 6. bit 29
	                                                                  {16,8}, // Channel 6. bit 30
	                                                                  {17,8}, // Channel 6. bit 31
	                                                                  {18,8}, // Channel 6. bit 32
	                                                                  {18,7}, // Channel 6. bit 33
	                                                                  {17,7}, // Channel 6. bit 34
	                                                                  {16,7}, // Channel 6. bit 35
	                                                                  {19,8}, // Channel 6. bit 36
	                                                                  {20,8}, // Channel 6. bit 37                                                           {0,0} // 0
	                                                                  {21,8}, // Channel 6. bit 38
	                                                                  {21,7}, // Channel 6. bit 39
	                                                                  {20,7}, // Channel 6. bit 40
	                                                                  {19,7}, // Channel 6. bit 41
	                                                                  {EMPTY,EMPTY}, // Channel 6. bit 42
	                                                                  {23,8}, // Channel 6. bit 43
	                                                                  {23,7}, // Channel 6. bit 44
	                                                                  {22,6}, // Channel 6. bit 45
	                                                                  {22,7}, // Channel 6. bit 46                                                            {0,0} // 0
	                                                                  {22,8}, // Channel 6. bit 47
	                                                                  {END,END}, // Channel 6. bit 48
	                                                                  {0,0}, // Channel 6. bit 49
	                                                                  {0,0}, // Channel 6. bit 50
	                                                                  {0,0}, // Channel 6. bit 51
	                                                                  {0,0}, // Channel 6. bit 52
	                                                                  {0,0}, // Channel 6. bit 53
	                                                                  {0,0}, // Channel 6. bit 54
	                                                                  {0,0}, // Channel 6. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 56
	                                                                  {0,0}, // Channel 6. bit 57
	                                                                  {0,0}, // Channel 6. bit 58
	                                                                  {0,0}, // Channel 6. bit 59
	                                                                  {0,0}, // Channel 6. bit 60
	                                                                  {0,0}, // Channel 6. bit 61
	                                                                  {0,0}, // Channel 6. bit 62
	                                                                  {0,0}, // Channel 6. bit 63
	                                                                  {0,0}, // Channel 6. bit 64
	                                                                  {0,0}, // Channel 6. bit 65
	                                                                  {0,0}, // Channel 6. bit 66
	                                                                  {0,0}, // Channel 6. bit 67
	                                                                  {0,0}, // Channel 6. bit 68
	                                                                  {0,0}, // Channel 6. bit 69
	                                                                  {0,0}, // Channel 6. bit 70
	                                                                  {0,0}, // Channel 6. bit 71
	                                                                  {0,0}},// Channel 6. bit 72
	                                                                  
	                                                                  {{0,1},// Channel 7. bit 0
	                                                                  {1,1}, // Channel 7. bit 1
	                                                                  {2,1}, // Channel 7. bit 2
	                                                                  {2,0}, // Channel 7. bit 3
	                                                                  {1,0}, // Channel 7. bit 4
	                                                                  {0,0}, // Channel 7. bit 5
	                                                                  {3,1}, // Channel 7. bit 6
	                                                                  {4,1}, // Channel 7. bit 7
	                                                                  {5,1}, // Channel 7. bit 8
	                                                                  {5,0}, // Channel 7. bit 9
	                                                                  {4,0}, // Channel 7. bit 10
	                                                                  {3,0}, // Channel 7. bit 11
	                                                                  {6,1}, // Channel 7. bit 12
	                                                                  {7,1}, // Channel 7. bit 13
	                                                                  {8,1}, // Channel 7. bit 14
	                                                                  {8,0}, // Channel 7. bit 15
	                                                                  {7,0}, // Channel 7. bit 16
	                                                                  {6,0}, // Channel 7. bit 17
	                                                                  {9,2}, // Channel 7. bit 18
	                                                                  {10,2}, // Channel 7. bit 19                                                             {0,0} // 0
	                                                                  {11,2}, // Channel 7. bit 20
	                                                                  {11,1}, // Channel 7. bit 21
	                                                                  {10,1}, // Channel 7. bit 22
	                                                                  {9,1}, // Channel 7. bit 23
	                                                                  {12,2}, // Channel 7. bit 24
	                                                                  {13,2}, // Channel 7. bit 25
	                                                                  {14,2}, // Channel 7. bit 26
	                                                                  {14,1}, // Channel 7. bit 27
	                                                                  {13,1}, // Channel 7. bit 28                                                            {0,0} // 0
	                                                                  {12,1}, // Channel 7. bit 29
	                                                                  {15,2}, // Channel 7. bit 30
	                                                                  {16,2}, // Channel 7. bit 31
	                                                                  {17,2}, // Channel 7. bit 32
	                                                                  {17,1}, // Channel 7. bit 33
	                                                                  {16,1}, // Channel 7. bit 34
	                                                                  {15,1}, // Channel 7. bit 35
	                                                                  {18,2}, // Channel 7. bit 36
	                                                                  {19,2}, // Channel 7. bit 37                                                           {0,0} // 0
	                                                                  {20,2}, // Channel 7. bit 38
	                                                                  {20,1}, // Channel 7. bit 39
	                                                                  {19,1}, // Channel 7. bit 40
	                                                                  {18,1}, // Channel 7. bit 41
	                                                                  {EMPTY,EMPTY}, // Channel 7. bit 42
	                                                                  {21,3}, // Channel 7. bit 43
	                                                                  {21,4}, // Channel 7. bit 44
	                                                                  {22,3}, // Channel 7. bit 45
	                                                                  {EMPTY,EMPTY}, // Channel 7. bit 46                                                            {0,0} // 0
	                                                                  {EMPTY,EMPTY}, // Channel 7. bit 47
	                                                                  {END,END}, // Channel 7. bit 48
	                                                                  {0,0}, // Channel 7. bit 49
	                                                                  {0,0}, // Channel 7. bit 50
	                                                                  {0,0}, // Channel 7. bit 51
	                                                                  {0,0}, // Channel 7. bit 52
	                                                                  {0,0}, // Channel 7. bit 53
	                                                                  {0,0}, // Channel 7. bit 54
	                                                                  {0,0}, // Channel 7. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 56
	                                                                  {0,0}, // Channel 7. bit 57
	                                                                  {0,0}, // Channel 7. bit 58
	                                                                  {0,0}, // Channel 7. bit 59
	                                                                  {0,0}, // Channel 7. bit 60
	                                                                  {0,0}, // Channel 7. bit 61
	                                                                  {0,0}, // Channel 7. bit 62
	                                                                  {0,0}, // Channel 7. bit 63
	                                                                  {0,0}, // Channel 7. bit 64
	                                                                  {0,0}, // Channel 7. bit 65
	                                                                  {0,0}, // Channel 7. bit 66
	                                                                  {0,0}, // Channel 7. bit 67
	                                                                  {0,0}, // Channel 7. bit 68
	                                                                  {0,0}, // Channel 7. bit 69
	                                                                  {0,0}, // Channel 7. bit 70
	                                                                  {0,0}, // Channel 7. bit 71
	                                                                  {0,0}}}; // Channel 7. bit 72
	                                                                  
	                                                                  
	                                                                   #elif SIDE == RIGHT
	                                                                {{{ 5, 8}, // Channel 0. bit 0
	                                                                  { 6, 7}, // Channel 0. bit 1
	                                                                  { 7, 6}, // Channel 0. bit 2
	                                                                  { 8, 6}, // Channel 0. bit 3
	                                                                  { 7, 7}, // Channel 0. bit 4
	                                                                  { 6, 8}, // Channel 0. bit 5
	                                                                  {EMPTY,EMPTY}, // Channel 0. bit 6
	                                                                  { 8, 4}, // Channel 0. bit 7
	                                                                  { 9, 3}, // Channel 0. bit 8
	                                                                  {10, 3}, // Channel 0. bit 9
	                                                                  { 9, 4}, // Channel 0. bit 10
	                                                                  { 8, 5}, // Channel 0. bit 11
	                                                                  {13, 0}, // Channel 0. bit 12
	                                                                  {12, 1}, // Channel 0. bit 13
	                                                                  {11, 2}, // Channel 0. bit 14
	                                                                  {10, 2}, // Channel 0. bit 15
	                                                                  {11, 1}, // Channel 0. bit 16
	                                                                  {12, 0}, // Channel 0. bit 17
	                                                                  {11, 3}, // Channel 0. bit 18
	                                                                  {12, 2}, // Channel 0. bit 19                                                             {0,0} // 0
	                                                                  {13, 1}, // Channel 0. bit 20
	                                                                  {14, 1}, // Channel 0. bit 21
	                                                                  {13, 2}, // Channel 0. bit 22
	                                                                  {12, 3}, // Channel 0. bit 23
	                                                                  {13, 3}, // Channel 0. bit 24
	                                                                  {14, 2}, // Channel 0. bit 25
	                                                                  {15, 1}, // Channel 0. bit 26
	                                                                  {16, 1}, // Channel 0. bit 27
	                                                                  {15, 2}, // Channel 0. bit 28                                                            {0,0} // 0
	                                                                  {14, 3}, // Channel 0. bit 29
	                                                                  {15, 3}, // Channel 0. bit 30
	                                                                  {16, 2}, // Channel 0. bit 31
	                                                                  {17, 1}, // Channel 0. bit 32
	                                                                  {18, 1}, // Channel 0. bit 33
	                                                                  {17, 2}, // Channel 0. bit 34
	                                                                  {16, 3}, // Channel 0. bit 35
	                                                                  {17, 3}, // Channel 0. bit 36
	                                                                  {18, 2}, // Channel 0. bit 37                                                           {0,0} // 0
	                                                                  {19, 1}, // Channel 0. bit 38
	                                                                  {20, 1}, // Channel 0. bit 39
	                                                                  {19, 2}, // Channel 0. bit 40
	                                                                  {18, 3}, // Channel 0. bit 41
	                                                                  {19, 3}, // Channel 0. bit 42
	                                                                  {20, 2}, // Channel 0. bit 43
	                                                                  {21, 1}, // Channel 0. bit 44
	                                                                  {22, 1}, // Channel 0. bit 45
	                                                                  {21, 2}, // Channel 0. bit 46                                                            {0,0} // 0
	                                                                  {20, 3}, // Channel 0. bit 47
	                                                                  {21, 3}, // Channel 0. bit 48
	                                                                  {22, 2}, // Channel 0. bit 49
	                                                                  {23, 1}, // Channel 0. bit 50
	                                                                  {24, 1}, // Channel 0. bit 51
	                                                                  {23, 2}, // Channel 0. bit 52
	                                                                  {22, 3}, // Channel 0. bit 53
	                                                                  {EMPTY,EMPTY}, // Channel 0. bit 54
	                                                                  {24, 2}, // Channel 0. bit 55                                                              {0,0} // 0
	                                                                  {25, 2}, // Channel 0. bit 56
	                                                                  {25, 3}, // Channel 0. bit 57
	                                                                  {24, 3}, // Channel 0. bit 58
	                                                                  {23, 3}, // Channel 0. bit 59
	                                                                  {26, 2}, //Channel 0. bit 60
	                                                                  {27, 2}, // Channel 0. bit 61
	                                                                  {28, 2}, // Channel 0. bit 62
	                                                                  {28, 3}, // Channel 0. bit 63
	                                                                  {27, 3}, // Channel 0. bit 64
	                                                                  {26, 3}, // Channel 0. bit 65
	                                                                  {29, 2}, // Channel 0. bit 66
	                                                                  {30, 2}, // Channel 0. bit 67
	                                                                  {EMPTY,EMPTY}, // Channel 0. bit 68
	                                                                  {28, 6}, // Channel 0. bit 69
	                                                                  {EMPTY,EMPTY}, // Channel 0. bit 70
	                                                                  {29, 3}, // Channel 0. bit 71
	                                                                  {END,END} // Channel 0. bit 72
	                                                                  },
	                                                                  {
		                                                              { 1,13}, // Channel 1. bit 0
		                                                              { 2,13}, // Channel 1. bit 1
		                                                              { 3,13}, // Channel 1. bit 2
		                                                              { 3,14}, // Channel 1. bit 3
		                                                              { 2,14}, // Channel 1. bit 4
		                                                              { 1,14}, // Channel 1. bit 5
		                                                              { 4,13}, // Channel 1. bit 6
		                                                              { 5,13}, // Channel 1. bit 7
		                                                              { 6,13}, // Channel 1. bit 8
		                                                              { 6,14}, // Channel 1. bit 9
		                                                              { 5,14}, // Channel 1. bit 10
		                                                              { 4,14}, // Channel 1. bit 11
		                                                              { 7,13}, // Channel 1. bit 12
	                                                                  { 8,13}, // Channel 1. bit 13
	                                                                  { 9,13}, // Channel 1. bit 14
	                                                                  { 9,14}, // Channel 1. bit 15
	                                                                  { 8,14}, // Channel 1. bit 16
	                                                                  { 7,14}, // Channel 1. bit 17
	                                                                  {10,12}, // Channel 1. bit 18
	                                                                  {11,12}, // Channel 1. bit 19                                                             {0,0} // 0
	                                                                  {12,12}, // Channel 1. bit 20
	                                                                  {12,13}, // Channel 1. bit 21
	                                                                  {11,13}, // Channel 1. bit 22
	                                                                  {10,13}, // Channel 1. bit 23
	                                                                  {10,12}, // Channel 1. bit 24
	                                                                  {14,12}, // Channel 1. bit 25
	                                                                  {15,12}, // Channel 1. bit 26
	                                                                  {15,13}, // Channel 1. bit 27
	                                                                  {14,13}, // Channel 1. bit 28                                                            {0,0} // 0
	                                                                  {13,13}, // Channel 1. bit 29
	                                                                  {16,12}, // Channel 1. bit 30
	                                                                  {17,12}, // Channel 1. bit 31
	                                                                  {18,12}, // Channel 1. bit 32
	                                                                  {18,13}, // Channel 1. bit 33
	                                                                  {17,13}, // Channel 1. bit 34
	                                                                  {16,13}, // Channel 1. bit 35
	                                                                  {19,12}, // Channel 1. bit 36
	                                                                  {20,12}, // Channel 1. bit 37                                                           {0,0} // 0
	                                                                  {21,12}, // Channel 1. bit 38
	                                                                  {21,13}, // Channel 1. bit 39
	                                                                  {20,13}, // Channel 1. bit 40
	                                                                  {19,13}, // Channel 1. bit 41
	                                                                  {22,12}, // Channel 1. bit 42
	                                                                  {23,12}, // Channel 1. bit 43
	                                                                  {24,12}, // Channel 1. bit 44
	                                                                  {24,13}, // Channel 1. bit 45
	                                                                  {23,13}, // Channel 1. bit 46                                                            {0,0} // 0
	                                                                  {22, 13}, // Channel 1. bit 47
	                                                                  {END,END}, // Channel 1. bit 48
	                                                                  {0,0}, // Channel 1. bit 49
	                                                                  {0,0}, // Channel 1. bit 50
	                                                                  {0,0}, // Channel 1. bit 51
	                                                                  {0,0}, // Channel 1. bit 52
	                                                                  {0,0}, // Channel 1. bit 53
	                                                                  {0,0}, // Channel 1. bit 54
	                                                                  {0,0}, // Channel 1. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 1. bit 56
	                                                                  {0,0}, // Channel 1. bit 57
	                                                                  {0,0}, // Channel 1. bit 58
	                                                                  {0,0}, // Channel 1. bit 59
	                                                                  {0,0}, // Channel 1. bit 60
	                                                                  {0,0}, // Channel 1. bit 61
	                                                                  {0,0}, // Channel 1. bit 62
	                                                                  {0,0}, // Channel 1. bit 63
	                                                                  {0,0}, // Channel 1. bit 64
	                                                                  {0,0}, // Channel 1. bit 65
	                                                                  {0,0}, // Channel 1. bit 66
	                                                                  {0,0}, // Channel 1. bit 67
	                                                                  {0,0}, // Channel 1. bit 68
	                                                                  {0,0}, // Channel 1. bit 69
	                                                                  {0,0}, // Channel 1. bit 70
	                                                                  {0,0}, // Channel 1. bit 71
	                                                                  {0,0}},// Channel 1. bit 72
	                                                                  
	                                                                  {{11,10}, // Channel 2. bit 0
	                                                                  {10,11}, // Channel 2. bit  1
	                                                                  { 9,12}, // Channel 2. bit  2
	                                                                  { 8,12}, // Channel 2. bit  3
	                                                                  { 9,11}, // Channel 2. bit  4
	                                                                  {10,10}, // Channel 2. bit  5
	                                                                  {EMPTY,EMPTY}, // Channel 2. bit  6
	                                                                  {12,10}, // Channel 2. bit  7
	                                                                  {13,10}, // Channel 2. bit  8
	                                                                  {13,11}, // Channel 2. bit  9
	                                                                  {12,11}, // Channel 2. bit  10
	                                                                  {11,11}, // Channel 2. bit  11
	                                                                  {14,10}, // Channel 2. bit  12
	                                                                  {15,10}, // Channel 2. bit  13
	                                                                  {16,10}, // Channel 2. bit  14
	                                                                  {16,11}, // Channel 2. bit  15
	                                                                  {15,11}, // Channel 2. bit  16
	                                                                  {14,11}, // Channel 2. bit  17
	                                                                  {17,10}, // Channel 2. bit  18
	                                                                  {18,10}, // Channel 2. bit  19                                                             {0,0} // 0
	                                                                  {19,10}, // Channel 2. bit  20
	                                                                  {19,11}, // Channel 2. bit  21
	                                                                  {18,11}, // Channel 2. bit  22
	                                                                  {17,11}, // Channel 2. bit  23
	                                                                  {20,10}, // Channel 2. bit  24
	                                                                  {21,10}, // Channel 2. bit  25
	                                                                  {22,10}, // Channel 2. bit  26
	                                                                  {22,11}, // Channel 2. bit  27
	                                                                  {21,11}, // Channel 2. bit  28                                                            {0,0} // 0
	                                                                  {20,11}, // Channel 2. bit  29
	                                                                  {23,10}, // Channel 2. bit  30
	                                                                  {24,10}, // Channel 2. bit  31
	                                                                  {25,10}, // Channel 2. bit  32
	                                                                  {25,11}, // Channel 2. bit  33
	                                                                  {24,11}, // Channel 2. bit  34
	                                                                  {23,11}, // Channel 2. bit  35
	                                                                  {END,END}, // Channel 2. bit  36
	                                                                  {0,0}, // Channel 2. bit  37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 2. bit  38
	                                                                  {0,0}, // Channel 2. bit  39
	                                                                  {0,0}, // Channel 2. bit  40
	                                                                  {0,0}, // Channel 2. bit  41
	                                                                  {0,0}, // Channel 2. bit  42
	                                                                  {0,0}, // Channel 2. bit  43
	                                                                  {0,0}, // Channel 2. bit  44
	                                                                  {0,0}, // Channel 2. bit  45
	                                                                  {0,0}, // Channel 2. bit  46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 2. bit  47
	                                                                  {0,0}, // Channel 2. bit  48
	                                                                  {0,0}, // Channel 2. bit  49
	                                                                  {0,0}, // Channel 2. bit  50
	                                                                  {0,0}, // Channel 2. bit  51
	                                                                  {0,0}, // Channel 2. bit  52
	                                                                  {0,0}, // Channel 2. bit  53
	                                                                  {0,0}, // Channel 2. bit  54
	                                                                  {0,0}, // Channel 2. bit  55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 2. bit  56
	                                                                  {0,0}, // Channel 2. bit  57
	                                                                  {0,0}, // Channel 2. bit  58
	                                                                  {0,0}, // Channel 2. bit  59
	                                                                  {0,0}, // Channel 2. bit  60
	                                                                  {0,0}, // Channel 2. bit  61
	                                                                  {0,0}, // Channel 2. bit  62
	                                                                  {0,0}, // Channel 2. bit  63
	                                                                  {0,0}, // Channel 2. bit  64
	                                                                  {0,0}, // Channel 2. bit  65
	                                                                  {0,0}, // Channel 2. bit  66
	                                                                  {0,0}, // Channel 2. bit  67
	                                                                  {0,0}, // Channel 2. bit  68
	                                                                  {0,0}, // Channel 2. bit  69
	                                                                  {0,0}, // Channel 2. bit  70
	                                                                  {0,0}, // Channel 2. bit  71
	                                                                  {0,0}}, //  Channel 2. bit  72 
	                                                                  
	                                                                  {{7,8}, // Channel 3. bit  0
	                                                                  {8,8}, // Channel 3. bit 1
	                                                                  {8,7}, // Channel 3. bit 2
	                                                                  {9,6}, // Channel 3. bit 3
	                                                                  {9,7}, // Channel 3. bit 4
	                                                                  {9,8}, // Channel 3. bit 5
	                                                                  {10,6}, // Channel 3. bit 6
	                                                                  {11,6}, // Channel 3. bit 7
	                                                                  {12,6}, // Channel 3. bit 8
	                                                                  {12,7}, // Channel 3. bit 9
	                                                                  {11,7}, // Channel 3. bit 10
	                                                                  {10,7}, // Channel 3. bit 11
	                                                                  {13,6}, // Channel 3. bit 12
	                                                                  {14,6}, // Channel 3. bit 13
	                                                                  {15,6}, // Channel 3. bit 14
	                                                                  {15,7}, // Channel 3. bit 15
	                                                                  {14,7}, // Channel 3. bit 16
	                                                                  {13,7}, // Channel 3. bit 17
	                                                                  {16,6}, // Channel 3. bit 18
	                                                                  {17,6}, // Channel 3. bit 19                                                             {0,0} // 0
	                                                                  {18,6}, // Channel 3. bit 20
	                                                                  {18,7}, // Channel 3. bit 21
	                                                                  {17,7}, // Channel 3. bit 22
	                                                                  {16,7}, // Channel 3. bit 23
	                                                                  {19,6}, // Channel 3. bit 24
	                                                                  {20,6}, // Channel 3. bit 25
	                                                                  {21,6}, // Channel 3. bit 26
	                                                                  {21,7}, // Channel 3. bit 27
	                                                                  {20,7}, // Channel 3. bit 28                                                            {0,0} // 0
	                                                                  {19,7}, // Channel 3. bit 29
	                                                                  {22,6}, // Channel 3. bit 30
	                                                                  {23,6}, // Channel 3. bit 31
	                                                                  {24,6}, // Channel 3. bit 32
	                                                                  {24,7}, // Channel 3. bit 33
	                                                                  {23,7}, // Channel 3. bit 34
	                                                                  {22,7}, // Channel 3. bit 35
	                                                                  {25,6}, // Channel 3. bit 36
	                                                                  {26,6}, // Channel 3. bit 37                                                           {0,0} // 0
	                                                                  {27,6}, // Channel 3. bit 38
	                                                                  {27,7}, // Channel 3. bit 39
	                                                                  {26,7}, // Channel 3. bit 40
	                                                                  {25,7}, // Channel 3. bit 41
	                                                                  {END,END}, // Channel 3. bit 42
	                                                                  {0,0}, // Channel 3. bit 43
	                                                                  {0,0}, // Channel 3. bit 44
	                                                                  {0,0}, // Channel 3. bit 45
	                                                                  {0,0}, // Channel 3. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 47
	                                                                  {0,0}, // Channel 3. bit 48
	                                                                  {0,0}, // Channel 3. bit 49
	                                                                  {0,0}, // Channel 3. bit 50
	                                                                  {0,0}, // Channel 3. bit 51
	                                                                  {0,0}, // Channel 3. bit 52
	                                                                  {0,0}, // Channel 3. bit 53
	                                                                  {0,0}, // Channel 3. bit 54
	                                                                  {0,0}, // Channel 3. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 56
	                                                                  {0,0}, // Channel 3. bit 57
	                                                                  {0,0}, // Channel 3. bit 58
	                                                                  {0,0}, // Channel 3. bit 59
	                                                                  {0,0}, // Channel 3. bit 60
	                                                                  {0,0}, // Channel 3. bit 61
	                                                                  {0,0}, // Channel 3. bit 62
	                                                                  {0,0}, // Channel 3. bit 63
	                                                                  {0,0}, // Channel 3. bit 64
	                                                                  {0,0}, // Channel 3. bit 65
	                                                                  {0,0}, // Channel 3. bit 66
	                                                                  {0,0}, // Channel 3. bit 67
	                                                                  {0,0}, // Channel 3. bit 68
	                                                                  {0,0}, // Channel 3. bit 69
	                                                                  {0,0}, // Channel 3. bit 70
	                                                                  {0,0}, // Channel 3. bit 71
	                                                                  {0,0}},// Channel 3. bit 72
	                                                                  
	                                                                  {{10,8},// Channel 4. bit 0
	                                                                  {11,8}, // Channel 4. bit 1
	                                                                  {12,8}, // Channel 4. bit 2
	                                                                  {12,9}, // Channel 4. bit 3
	                                                                  {11,9}, // Channel 4. bit 4
	                                                                  {10,9}, // Channel 4. bit 5
	                                                                  {13,8}, // Channel 4. bit 6
	                                                                  {14,8}, // Channel 4. bit 7
	                                                                  {15,8}, // Channel 4. bit 8
	                                                                  {15,9}, // Channel 4. bit 9
	                                                                  {14,9}, // Channel 4. bit 10
	                                                                  {13,9}, // Channel 4. bit 11
	                                                                  {16,8}, // Channel 4. bit 12
	                                                                  {17,8}, // Channel 4. bit 13
	                                                                  {18,8}, // Channel 4. bit 14
	                                                                  {18,9}, // Channel 4. bit 15
	                                                                  {17,9}, // Channel 4. bit 16
	                                                                  {16,9}, // Channel 4. bit 17
	                                                                  {19,8}, // Channel 4. bit 18
	                                                                  {20,8}, // Channel 4. bit 19                                                             {0,0} // 0
	                                                                  {21,8}, // Channel 4. bit 20
	                                                                  {21,9}, // Channel 4. bit 21
	                                                                  {20,9}, // Channel 4. bit 22
	                                                                  {19,9}, // Channel 4. bit 23
	                                                                  {22,8}, // Channel 4. bit 24
	                                                                  {23,8}, // Channel 4. bit 25
	                                                                  {24,8}, // Channel 4. bit 26
	                                                                  {24,9}, // Channel 4. bit 27
	                                                                  {23,9}, // Channel 4. bit 28
	                                                                  {22,9}, // Channel 4. bit 29
	                                                                  {26,10},// Channel 4. bit 30
	                                                                  {26,9}, // Channel 4. bit 31
	                                                                  {25,9}, // Channel 4. bit 32
	                                                                  {25,8}, // Channel 4. bit 33
	                                                                  {26,8}, // Channel 4. bit 34
	                                                                  {27,8}, // Channel 4. bit 35
	                                                                  {END,END}, // Channel 4. bit 36                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 37
	                                                                  {0,0}, // Channel 4. bit 38
	                                                                  {0,0}, // Channel 4. bit 39
	                                                                  {0,0}, // Channel 4. bit 40
	                                                                  {0,0}, // Channel 4. bit 41
	                                                                  {0,0}, // Channel 4. bit 42
	                                                                  {0,0}, // Channel 4. bit 43
	                                                                  {0,0}, // Channel 4. bit 44
	                                                                  {0,0}, // Channel 4. bit 45
	                                                                  {0,0}, // Channel 4. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 47
	                                                                  {0,0}, // Channel 4. bit 48
	                                                                  {0,0}, // Channel 4. bit 49
	                                                                  {0,0}, // Channel 4. bit 50
	                                                                  {0,0}, // Channel 4. bit 51
	                                                                  {0,0}, // Channel 4. bit 52
	                                                                  {0,0}, // Channel 4. bit 53
	                                                                  {0,0}, // Channel 4. bit 54
	                                                                  {0,0}, // Channel 4. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 56
	                                                                  {0,0}, // Channel 4. bit 57
	                                                                  {0,0}, // Channel 4. bit 58
	                                                                  {0,0}, // Channel 4. bit 59
	                                                                  {0,0}, // Channel 4. bit 60
	                                                                  {0,0}, // Channel 4. bit 61
	                                                                  {0,0}, // Channel 4. bit 62
	                                                                  {0,0}, // Channel 4. bit 63
	                                                                  {0,0}, // Channel 4. bit 64
	                                                                  {0,0}, // Channel 4. bit 65
	                                                                  {0,0}, // Channel 4. bit 66
	                                                                  {0,0}, // Channel 4. bit 67
	                                                                  {0,0}, // Channel 4. bit 68
	                                                                  {0,0}, // Channel 4. bit 69
	                                                                  {0,0}, // Channel 4. bit 70
	                                                                  {0,0}, // Channel 4. bit 71
	                                                                  {0,0}},// Channel 4. bit 72
	                                                                  
	                                                                  {{EMPTY,EMPTY},// Channel 5. bit 0
	                                                                  {10,4}, // Channel 5. bit 1
	                                                                  {11,4}, // Channel 5. bit 2
	                                                                  {11,5}, // Channel 5. bit 3
	                                                                  {10,5}, // Channel 5. bit 4
	                                                                  {9,5}, // Channel 5. bit 5
	                                                                  {12,4}, // Channel 5. bit 6
	                                                                  {13,4}, // Channel 5. bit 7
	                                                                  {14,4}, // Channel 5. bit 8
	                                                                  {14,5}, // Channel 5. bit 9
	                                                                  {13,5}, // Channel 5. bit 10
	                                                                  {12,5}, // Channel 5. bit 11
	                                                                  {15,4}, // Channel 5. bit 12
	                                                                  {16,4}, // Channel 5. bit 13
	                                                                  {17,4}, // Channel 5. bit 14
	                                                                  {17,5}, // Channel 5. bit 15
	                                                                  {16,5}, // Channel 5. bit 16
	                                                                  {15,5}, // Channel 5. bit 17
	                                                                  {18,4}, // Channel 5. bit 18
	                                                                  {19,4}, // Channel 5. bit 19                                                             {0,0} // 0
	                                                                  {20,4}, // Channel 5. bit 20
	                                                                  {20,5}, // Channel 5. bit 21
	                                                                  {19,5}, // Channel 5. bit 22
	                                                                  {18,5}, // Channel 5. bit 23
	                                                                  {21,4}, // Channel 5. bit 24
	                                                                  {22,4}, // Channel 5. bit 25
	                                                                  {23,4}, // Channel 5. bit 26
	                                                                  {23,5}, // Channel 5. bit 27
	                                                                  {22,5}, // Channel 5. bit 28                                                            {0,0} // 0
	                                                                  {21,5}, // Channel 5. bit 29
	                                                                  {24,4}, // Channel 5. bit 30
	                                                                  {25,4}, // Channel 5. bit 31
	                                                                  {26,4}, // Channel 5. bit 32
	                                                                  {26,5}, // Channel 5. bit 33
	                                                                  {25,5},// Channel 5. bit 34
	                                                                  {24,5}, // Channel 5. bit 35
	                                                                  {25,12}, // Channel 5. bit 36
	                                                                  {28,5}, // Channel 5. bit 37                                                           {0,0} // 0
	                                                                  {27,5}, // Channel 5. bit 38
	                                                                  {27,4}, // Channel 5. bit 39
	                                                                  {28,4}, // Channel 5. bit 40
	                                                                  {29,4}, // Channel 5. bit 41
	                                                                  {END,END}, // Channel 5. bit 42
	                                                                  {0,0}, // Channel 5. bit 43
	                                                                  {0,0}, // Channel 5. bit 44
	                                                                  {0,0}, // Channel 5. bit 45
	                                                                  {0,0}, // Channel 5. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 5. bit 47
	                                                                  {0,0}, // Channel 5. bit 48
	                                                                  {0,0}, // Channel 5. bit 49
	                                                                  {0,0}, // Channel 5. bit 50
	                                                                  {0,0}, // Channel 5. bit 51
	                                                                  {0,0}, // Channel 5. bit 52
	                                                                  {0,0}, // Channel 5. bit 53
	                                                                  {0,0}, // Channel 5. bit 54
	                                                                  {0,0}, // Channel 5. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 5. bit 56
	                                                                  {0,0}, // Channel 5. bit 57
	                                                                  {0,0}, // Channel 5. bit 58
	                                                                  {0,0}, // Channel 5. bit 59
	                                                                  {0,0}, // Channel 5. bit 60
	                                                                  {0,0}, // Channel 5. bit 61
	                                                                  {0,0}, // Channel 5. bit 62
	                                                                  {0,0}, // Channel 5. bit 63
	                                                                  {0,0}, // Channel 5. bit 64
	                                                                  {0,0}, // Channel 5. bit 65
	                                                                  {0,0}, // Channel 5. bit 66
	                                                                  {0,0}, // Channel 5. bit 67
	                                                                  {0,0}, // Channel 5. bit 68
	                                                                  {0,0}, // Channel 5. bit 69
	                                                                  {0,0}, // Channel 5. bit 70
	                                                                  {0,0}, // Channel 5. bit 71
	                                                                  {0,0}},// Channel 5. bit 72
	                                                                  
	                                                                  {{0,0},// Channel 6. bit 0
	                                                                  {0,0}, // Channel 6. bit 1
	                                                                  {0,0}, // Channel 6. bit 2
	                                                                  {0,0}, // Channel 6. bit 3
	                                                                  {0,0}, // Channel 6. bit 4
	                                                                  {0,0}, // Channel 6. bit 5
	                                                                  {0,0}, // Channel 6. bit 6
	                                                                  {0,0}, // Channel 6. bit 7
	                                                                  {0,0}, // Channel 6. bit 8
	                                                                  {0,0}, // Channel 6. bit 9
	                                                                  {0,0}, // Channel 6. bit 10
	                                                                  {0,0}, // Channel 6. bit 11
	                                                                  {0,0}, // Channel 6. bit 12
	                                                                  {0,0}, // Channel 6. bit 13
	                                                                  {0,0}, // Channel 6. bit 14
	                                                                  {0,0}, // Channel 6. bit 15
	                                                                  {0,0}, // Channel 6. bit 16
	                                                                  {0,0}, // Channel 6. bit 17
	                                                                  {0,0}, // Channel 6. bit 18
	                                                                  {0,0}, // Channel 6. bit 19                                                             {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 20
	                                                                  {0,0}, // Channel 6. bit 21
	                                                                  {0,0}, // Channel 6. bit 22
	                                                                  {0,0}, // Channel 6. bit 23
	                                                                  {0,0}, // Channel 6. bit 24
	                                                                  {0,0}, // Channel 6. bit 25
	                                                                  {0,0}, // Channel 6. bit 26
	                                                                  {0,0}, // Channel 6. bit 27
	                                                                  {0,0}, // Channel 6. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 29
	                                                                  {0,0}, // Channel 6. bit 30
	                                                                  {0,0}, // Channel 6. bit 31
	                                                                  {0,0}, // Channel 6. bit 32
	                                                                  {0,0}, // Channel 6. bit 33
	                                                                  {0,0}, // Channel 6. bit 34
	                                                                  {0,0}, // Channel 6. bit 35
	                                                                  {0,0}, // Channel 6. bit 36
	                                                                  {0,0}, // Channel 6. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 38
	                                                                  {0,0}, // Channel 6. bit 39
	                                                                  {0,0}, // Channel 6. bit 40
	                                                                  {0,0}, // Channel 6. bit 41
	                                                                  {0,0}, // Channel 6. bit 42
	                                                                  {0,0}, // Channel 6. bit 43
	                                                                  {0,0}, // Channel 6. bit 44
	                                                                  {0,0}, // Channel 6. bit 45
	                                                                  {0,0}, // Channel 6. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 47
	                                                                  {0,0}, // Channel 6. bit 48
	                                                                  {0,0}, // Channel 6. bit 49
	                                                                  {0,0}, // Channel 6. bit 50
	                                                                  {0,0}, // Channel 6. bit 51
	                                                                  {0,0}, // Channel 6. bit 52
	                                                                  {0,0}, // Channel 6. bit 53
	                                                                  {0,0}, // Channel 6. bit 54
	                                                                  {0,0}, // Channel 6. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 56
	                                                                  {0,0}, // Channel 6. bit 57
	                                                                  {0,0}, // Channel 6. bit 58
	                                                                  {0,0}, // Channel 6. bit 59
	                                                                  {0,0}, // Channel 6. bit 60
	                                                                  {0,0}, // Channel 6. bit 61
	                                                                  {0,0}, // Channel 6. bit 62
	                                                                  {0,0}, // Channel 6. bit 63
	                                                                  {0,0}, // Channel 6. bit 64
	                                                                  {0,0}, // Channel 6. bit 65
	                                                                  {0,0}, // Channel 6. bit 66
	                                                                  {0,0}, // Channel 6. bit 67
	                                                                  {0,0}, // Channel 6. bit 68
	                                                                  {0,0}, // Channel 6. bit 69
	                                                                  {0,0}, // Channel 6. bit 70
	                                                                  {0,0}, // Channel 6. bit 71
	                                                                  {0,0}},// Channel 6. bit 72
	                                                                  
	                                                                  {{0,0},// Channel 7. bit 0
	                                                                  {0,0}, // Channel 7. bit 1
	                                                                  {0,0}, // Channel 7. bit 2
	                                                                  {0,0}, // Channel 7. bit 3
	                                                                  {0,0}, // Channel 7. bit 4
	                                                                  {0,0}, // Channel 7. bit 5
	                                                                  {0,0}, // Channel 7. bit 6
	                                                                  {0,0}, // Channel 7. bit 7
	                                                                  {0,0}, // Channel 7. bit 8
	                                                                  {0,0}, // Channel 7. bit 9
	                                                                  {0,0}, // Channel 7. bit 10
	                                                                  {0,0}, // Channel 7. bit 11
	                                                                  {0,0}, // Channel 7. bit 12
	                                                                  {0,0}, // Channel 7. bit 13
	                                                                  {0,0}, // Channel 7. bit 14
	                                                                  {0,0}, // Channel 7. bit 15
	                                                                  {0,0}, // Channel 7. bit 16
	                                                                  {0,0}, // Channel 7. bit 17
	                                                                  {0,0}, // Channel 7. bit 18
	                                                                  {0,0}, // Channel 7. bit 19                                                             {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 20
	                                                                  {0,0}, // Channel 7. bit 21
	                                                                  {0,0}, // Channel 7. bit 22
	                                                                  {0,0}, // Channel 7. bit 23
	                                                                  {0,0}, // Channel 7. bit 24
	                                                                  {0,0}, // Channel 7. bit 25
	                                                                  {0,0}, // Channel 7. bit 26
	                                                                  {0,0}, // Channel 7. bit 27
	                                                                  {0,0}, // Channel 7. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 29
	                                                                  {0,0}, // Channel 7. bit 30
	                                                                  {0,0}, // Channel 7. bit 31
	                                                                  {0,0}, // Channel 7. bit 32
	                                                                  {0,0}, // Channel 7. bit 33
	                                                                  {0,0}, // Channel 7. bit 34
	                                                                  {0,0}, // Channel 7. bit 35
	                                                                  {0,0}, // Channel 7. bit 36
	                                                                  {0,0}, // Channel 7. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 38
	                                                                  {0,0}, // Channel 7. bit 39
	                                                                  {0,0}, // Channel 7. bit 40
	                                                                  {0,0}, // Channel 7. bit 41
	                                                                  {0,0}, // Channel 7. bit 42
	                                                                  {0,0}, // Channel 7. bit 43
	                                                                  {0,0}, // Channel 7. bit 44
	                                                                  {0,0}, // Channel 7. bit 45
	                                                                  {0,0}, // Channel 7. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 47
	                                                                  {0,0}, // Channel 7. bit 48
	                                                                  {0,0}, // Channel 7. bit 49
	                                                                  {0,0}, // Channel 7. bit 50
	                                                                  {0,0}, // Channel 7. bit 51
	                                                                  {0,0}, // Channel 7. bit 52
	                                                                  {0,0}, // Channel 7. bit 53
	                                                                  {0,0}, // Channel 7. bit 54
	                                                                  {0,0}, // Channel 7. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 56
	                                                                  {0,0}, // Channel 7. bit 57
	                                                                  {0,0}, // Channel 7. bit 58
	                                                                  {0,0}, // Channel 7. bit 59
	                                                                  {0,0}, // Channel 7. bit 60
	                                                                  {0,0}, // Channel 7. bit 61
	                                                                  {0,0}, // Channel 7. bit 62
	                                                                  {0,0}, // Channel 7. bit 63
	                                                                  {0,0}, // Channel 7. bit 64
	                                                                  {0,0}, // Channel 7. bit 65
	                                                                  {0,0}, // Channel 7. bit 66
	                                                                  {0,0}, // Channel 7. bit 67
	                                                                  {0,0}, // Channel 7. bit 68
	                                                                  {0,0}, // Channel 7. bit 69
	                                                                  {0,0}, // Channel 7. bit 70
	                                                                  {0,0}, // Channel 7. bit 71
	                                                                  {0,0}}}; // Channel 7. bit 72
	                                                                   
	                                                                   #elif SIDE == FRONT
	                                                                   
	                                                                {{{EMPTY,EMPTY}, // Channel 0. bit 0
	                                                                  {10,1}, // Channel 0. bit 1
	                                                                  {9,0}, // Channel 0. bit 2
	                                                                  {8,0}, // Channel 0. bit 3
	                                                                  {9,1}, // Channel 0. bit 4
	                                                                  {10,2}, // Channel 0. bit 5
	                                                                  {9,2}, // Channel 0. bit 6
	                                                                  {8,1}, // Channel 0. bit 7
	                                                                  {7,0}, // Channel 0. bit 8
	                                                                  {6,0}, // Channel 0. bit 9
	                                                                  {7,1}, // Channel 0. bit 10
	                                                                  {8,2}, // Channel 0. bit 11
	                                                                  {7,2}, // Channel 0. bit 12
	                                                                  {6,1}, // Channel 0. bit 13
	                                                                  {5,0}, // Channel 0. bit 14
	                                                                  {4,0}, // Channel 0. bit 15
	                                                                  {5,1}, // Channel 0. bit 16
	                                                                  {6,2}, // Channel 0. bit 17
	                                                                  {5,2}, // Channel 0. bit 18
	                                                                  {4,1}, // Channel 0. bit 19                                                             {0,0} // 0
	                                                                  {3,0}, // Channel 0. bit 20
	                                                                  {2,0}, // Channel 0. bit 21
	                                                                  {3,1}, // Channel 0. bit 22
	                                                                  {4,2}, // Channel 0. bit 23
	                                                                  {END,END}, // Channel 0. bit 24
	                                                                  {0,0}, // Channel 0. bit 25
	                                                                  {0,0}, // Channel 0. bit 26
	                                                                  {0,0}, // Channel 0. bit 27
	                                                                  {0,0}, // Channel 0. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 0. bit 29
	                                                                  {0,0}, // Channel 0. bit 30
	                                                                  {0,0}, // Channel 0. bit 31
	                                                                  {0,0}, // Channel 0. bit 32
	                                                                  {0,0}, // Channel 0. bit 33
	                                                                  {0,0}, // Channel 0. bit 34
	                                                                  {0,0}, // Channel 0. bit 35
	                                                                  {0,0}, // Channel 0. bit 36
	                                                                  {0,0}, // Channel 0. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 0. bit 38
	                                                                  {0,0}, // Channel 0. bit 39
	                                                                  {0,0}, // Channel 0. bit 40
	                                                                  {0,0}, // Channel 0. bit 41
	                                                                  {0,0}, // Channel 0. bit 42
	                                                                  {0,0}, // Channel 0. bit 43
	                                                                  {0,0}, // Channel 0. bit 44
	                                                                  {0,0}, // Channel 0. bit 45
	                                                                  {0,0}, // Channel 0. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 0. bit 47
	                                                                  {0,0}, // Channel 0. bit 48
	                                                                  {0,0}, // Channel 0. bit 49
	                                                                  {0,0}, // Channel 0. bit 50
	                                                                  {0,0}, // Channel 0. bit 51
	                                                                  {0,0}, // Channel 0. bit 52
	                                                                  {0,0}, // Channel 0. bit 53
	                                                                  {0,0}, // Channel 0. bit 54
	                                                                  {0,0}, // Channel 0. bit 55
	                                                                  {0,0}, // Channel 0. bit 56
	                                                                  {0,0}, // Channel 0. bit 57
	                                                                  {0,0}, // Channel 0. bit 58
	                                                                  {0,0}, // Channel 0. bit 59
	                                                                  {0,0}, // Channel 0. bit 60
	                                                                  {0,0}, // Channel 0. bit 61
	                                                                  {0,0}, // Channel 0. bit 62
	                                                                  {0,0}, // Channel 0. bit 63
	                                                                  {0,0}, // Channel 0. bit 64
	                                                                  {0,0}, // Channel 0. bit 65
	                                                                  {0,0}, // Channel 0. bit 66
	                                                                  {0,0}, // Channel 0. bit 67
	                                                                  {0,0}, // Channel 0. bit 68
	                                                                  {0,0}, // Channel 0. bit 69
	                                                                  {0,0}, // Channel 0. bit 70
	                                                                  {0,0}, // Channel 0. bit 71
	                                                                  {0,0}}, // Channel 0. bit 72
	                                                                  
	                                                                  {{END,END}, // Channel 1. bit 0
	                                                                  {0,0}, // Channel 1. bit 1
	                                                                  {0,0}, // Channel 1. bit 2
	                                                                  {0,0}, // Channel 1. bit 3
	                                                                  {0,0}, // Channel 1. bit 4
	                                                                  {0,0}, // Channel 1. bit 5
	                                                                  {0,0}, // Channel 1. bit 6
	                                                                  {0,0}, // Channel 1. bit 7
	                                                                  {0,0}, // Channel 1. bit 8
	                                                                  {0,0}, // Channel 1. bit 9
	                                                                  {0,0}, // Channel 1. bit 10
	                                                                  {0,0}, // Channel 1. bit 11
	                                                                  {0,0}, // Channel 1. bit 12
	                                                                  {0,0}, // Channel 1. bit 13
	                                                                  {0,0}, // Channel 1. bit 14
	                                                                  {0,0}, // Channel 1. bit 15
	                                                                  {0,0}, // Channel 1. bit 16
	                                                                  {0,0}, // Channel 1. bit 17
	                                                                  {0,0}, // Channel 1. bit 18
	                                                                  {0,0}, // Channel 1. bit 19                                                             {0,0} // 0
	                                                                  {0,0}, // Channel 1. bit 20
	                                                                  {0,0}, // Channel 1. bit 21
	                                                                  {0,0}, // Channel 1. bit 22
	                                                                  {0,0}, // Channel 1. bit 23
	                                                                  {0,0}, // Channel 1. bit 24
	                                                                  {0,0}, // Channel 1. bit 25
	                                                                  {0,0}, // Channel 1. bit 26
	                                                                  {0,0}, // Channel 1. bit 27
	                                                                  {0,0}, // Channel 1. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 1. bit 29
	                                                                  {0,0}, // Channel 1. bit 30
	                                                                  {0,0}, // Channel 1. bit 31
	                                                                  {0,0}, // Channel 1. bit 32
	                                                                  {0,0}, // Channel 1. bit 33
	                                                                  {0,0}, // Channel 1. bit 34
	                                                                  {0,0}, // Channel 1. bit 35
	                                                                  {0,0}, // Channel 1. bit 36
	                                                                  {0,0}, // Channel 1. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 1. bit 38
	                                                                  {0,0}, // Channel 1. bit 39
	                                                                  {0,0}, // Channel 1. bit 40
	                                                                  {0,0}, // Channel 1. bit 41
	                                                                  {0,0}, // Channel 1. bit 42
	                                                                  {0,0}, // Channel 1. bit 43
	                                                                  {0,0}, // Channel 1. bit 44
	                                                                  {0,0}, // Channel 1. bit 45
	                                                                  {0,0}, // Channel 1. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 1. bit 47
	                                                                  {0,0}, // Channel 1. bit 48
	                                                                  {0,0}, // Channel 1. bit 49
	                                                                  {0,0}, // Channel 1. bit 50
	                                                                  {0,0}, // Channel 1. bit 51
	                                                                  {0,0}, // Channel 1. bit 52
	                                                                  {0,0}, // Channel 1. bit 53
	                                                                  {0,0}, // Channel 1. bit 54
	                                                                  {0,0}, // Channel 1. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 1. bit 56
	                                                                  {0,0}, // Channel 1. bit 57
	                                                                  {0,0}, // Channel 1. bit 58
	                                                                  {0,0}, // Channel 1. bit 59
	                                                                  {0,0}, // Channel 1. bit 60
	                                                                  {0,0}, // Channel 1. bit 61
	                                                                  {0,0}, // Channel 1. bit 62
	                                                                  {0,0}, // Channel 1. bit 63
	                                                                  {0,0}, // Channel 1. bit 64
	                                                                  {0,0}, // Channel 1. bit 65
	                                                                  {0,0}, // Channel 1. bit 66
	                                                                  {0,0}, // Channel 1. bit 67
	                                                                  {0,0}, // Channel 1. bit 68
	                                                                  {0,0}, // Channel 1. bit 69
	                                                                  {0,0}, // Channel 1. bit 70
	                                                                  {0,0}, // Channel 1. bit 71
	                                                                  {0,0}},// Channel 1. bit 72
	                                                                  
	                                                                  {{11,3}, // Channel 2. bit 0
	                                                                  {10,3}, // Channel 2. bit  1
	                                                                  {9,3}, // Channel 2. bit  2
	                                                                  {9,4}, // Channel 2. bit  3
	                                                                  {10,4}, // Channel 2. bit  4
	                                                                  {11,4}, // Channel 2. bit  5
	                                                                  {8,3}, // Channel 2. bit  6
	                                                                  {7,3}, // Channel 2. bit  7
	                                                                  {6,3}, // Channel 2. bit  8
	                                                                  {6,4}, // Channel 2. bit  9
	                                                                  {7,4}, // Channel 2. bit  10
	                                                                  {8,4}, // Channel 2. bit  11
	                                                                  {EMPTY,EMPTY}, // Channel 2. bit  12
	                                                                  {4,3}, // Channel 2. bit  13
	                                                                  {4,4}, // Channel 2. bit  14
	                                                                  {5,5}, // Channel 2. bit  15
	                                                                  {5,4}, // Channel 2. bit  16
	                                                                  {5,3}, // Channel 2. bit  17
	                                                                  {6,7}, // Channel 2. bit  18
	                                                                  {5,6}, // Channel 2. bit  19                                                             {0,0} // 0
	                                                                  {4,5}, // Channel 2. bit  20
	                                                                  {3,5}, // Channel 2. bit  21
	                                                                  {4,6}, // Channel 2. bit  22
	                                                                  {5,7}, // Channel 2. bit  23
	                                                                  {3,4}, // Channel 2. bit  24
	                                                                  {3,3}, // Channel 2. bit  25
	                                                                  {3,2}, // Channel 2. bit  26
	                                                                  {3,1}, // Channel 2. bit  27
	                                                                  {2,2}, // Channel 2. bit  28                                                            {0,0} // 0
	                                                                  {2,3}, // Channel 2. bit  29
	                                                                  {END,END}, // Channel 2. bit  30
	                                                                  {0,0}, // Channel 2. bit  31
	                                                                  {0,0}, // Channel 2. bit  32
	                                                                  {0,0}, // Channel 2. bit  33
	                                                                  {0,0}, // Channel 2. bit  34
	                                                                  {0,0}, // Channel 2. bit  35
	                                                                  {0,0}, // Channel 2. bit  36
	                                                                  {0,0}, // Channel 2. bit  37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 2. bit  38
	                                                                  {0,0}, // Channel 2. bit  39
	                                                                  {0,0}, // Channel 2. bit  40
	                                                                  {0,0}, // Channel 2. bit  41
	                                                                  {0,0}, // Channel 2. bit  42
	                                                                  {0,0}, // Channel 2. bit  43
	                                                                  {0,0}, // Channel 2. bit  44
	                                                                  {0,0}, // Channel 2. bit  45
	                                                                  {0,0}, // Channel 2. bit  46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 2. bit  47
	                                                                  {0,0}, // Channel 2. bit  48
	                                                                  {0,0}, // Channel 2. bit  49
	                                                                  {0,0}, // Channel 2. bit  50
	                                                                  {0,0}, // Channel 2. bit  51
	                                                                  {0,0}, // Channel 2. bit  52
	                                                                  {0,0}, // Channel 2. bit  53
	                                                                  {0,0}, // Channel 2. bit  54
	                                                                  {0,0}, // Channel 2. bit  55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 2. bit  56
	                                                                  {0,0}, // Channel 2. bit  57
	                                                                  {0,0}, // Channel 2. bit  58
	                                                                  {0,0}, // Channel 2. bit  59
	                                                                  {0,0}, // Channel 2. bit  60
	                                                                  {0,0}, // Channel 2. bit  61
	                                                                  {0,0}, // Channel 2. bit  62
	                                                                  {0,0}, // Channel 2. bit  63
	                                                                  {0,0}, // Channel 2. bit  64
	                                                                  {0,0}, // Channel 2. bit  65
	                                                                  {0,0}, // Channel 2. bit  66
	                                                                  {0,0}, // Channel 2. bit  67
	                                                                  {0,0}, // Channel 2. bit  68
	                                                                  {0,0}, // Channel 2. bit  69
	                                                                  {0,0}, // Channel 2. bit  70
	                                                                  {0,0}, // Channel 2. bit  71
	                                                                  {0,0}},// Channel 2. bit  72
	                                                                  
	                                                                  {{END,END}, // Channel 3. bit  0
	                                                                  {0,0}, // Channel 3. bit 1
	                                                                  {0,0}, // Channel 3. bit 2
	                                                                  {0,0}, // Channel 3. bit 3
	                                                                  {0,0}, // Channel 3. bit 4
	                                                                  {0,0}, // Channel 3. bit 5
	                                                                  {0,0}, // Channel 3. bit 6
	                                                                  {0,0}, // Channel 3. bit 7
	                                                                  {0,0}, // Channel 3. bit 8
	                                                                  {0,0}, // Channel 3. bit 9
	                                                                  {0,0}, // Channel 3. bit 10
	                                                                  {0,0}, // Channel 3. bit 11
	                                                                  {0,0}, // Channel 3. bit 12
	                                                                  {0,0}, // Channel 3. bit 13
	                                                                  {0,0}, // Channel 3. bit 14
	                                                                  {0,0}, // Channel 3. bit 15
	                                                                  {0,0}, // Channel 3. bit 16
	                                                                  {0,0}, // Channel 3. bit 17
	                                                                  {0,0}, // Channel 3. bit 18
	                                                                  {0,0}, // Channel 3. bit 19                                                             {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 20
	                                                                  {0,0}, // Channel 3. bit 21
	                                                                  {0,0}, // Channel 3. bit 22
	                                                                  {0,0}, // Channel 3. bit 23
	                                                                  {0,0}, // Channel 3. bit 24
	                                                                  {0,0}, // Channel 3. bit 25
	                                                                  {0,0}, // Channel 3. bit 26
	                                                                  {0,0}, // Channel 3. bit 27
	                                                                  {0,0}, // Channel 3. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 29
	                                                                  {0,0}, // Channel 3. bit 30
	                                                                  {0,0}, // Channel 3. bit 31
	                                                                  {0,0}, // Channel 3. bit 32
	                                                                  {0,0}, // Channel 3. bit 33
	                                                                  {0,0}, // Channel 3. bit 34
	                                                                  {0,0}, // Channel 3. bit 35
	                                                                  {0,0}, // Channel 3. bit 36
	                                                                  {0,0}, // Channel 3. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 38
	                                                                  {0,0}, // Channel 3. bit 39
	                                                                  {0,0}, // Channel 3. bit 40
	                                                                  {0,0}, // Channel 3. bit 41
	                                                                  {0,0}, // Channel 3. bit 42
	                                                                  {0,0}, // Channel 3. bit 43
	                                                                  {0,0}, // Channel 3. bit 44
	                                                                  {0,0}, // Channel 3. bit 45
	                                                                  {0,0}, // Channel 3. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 47
	                                                                  {0,0}, // Channel 3. bit 48
	                                                                  {0,0}, // Channel 3. bit 49
	                                                                  {0,0}, // Channel 3. bit 50
	                                                                  {0,0}, // Channel 3. bit 51
	                                                                  {0,0}, // Channel 3. bit 52
	                                                                  {0,0}, // Channel 3. bit 53
	                                                                  {0,0}, // Channel 3. bit 54
	                                                                  {0,0}, // Channel 3. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 3. bit 56
	                                                                  {0,0}, // Channel 3. bit 57
	                                                                  {0,0}, // Channel 3. bit 58
	                                                                  {0,0}, // Channel 3. bit 59
	                                                                  {0,0}, // Channel 3. bit 60
	                                                                  {0,0}, // Channel 3. bit 61
	                                                                  {0,0}, // Channel 3. bit 62
	                                                                  {0,0}, // Channel 3. bit 63
	                                                                  {0,0}, // Channel 3. bit 64
	                                                                  {0,0}, // Channel 3. bit 65
	                                                                  {0,0}, // Channel 3. bit 66
	                                                                  {0,0}, // Channel 3. bit 67
	                                                                  {0,0}, // Channel 3. bit 68
	                                                                  {0,0}, // Channel 3. bit 69
	                                                                  {0,0}, // Channel 3. bit 70
	                                                                  {0,0}, // Channel 3. bit 71
	                                                                  {0,0}},// Channel 3. bit 72
	                                                                  
	                                                                  {{13,7},// Channel 4. bit 0
	                                                                  {12,7}, // Channel 4. bit 1
	                                                                  {11,7}, // Channel 4. bit 2
	                                                                  {12,9}, // Channel 4. bit 3
	                                                                  {13,9}, // Channel 4. bit 4
	                                                                  {13,8}, // Channel 4. bit 5
	                                                                  {END,END}, // Channel 4. bit 6
	                                                                  {0,0}, // Channel 4. bit 7
	                                                                  {0,0}, // Channel 4. bit 8
	                                                                  {0,0}, // Channel 4. bit 9
	                                                                  {0,0}, // Channel 4. bit 10
	                                                                  {0,0}, // Channel 4. bit 11
	                                                                  {0,0}, // Channel 4. bit 12
	                                                                  {0,0}, // Channel 4. bit 13
	                                                                  {0,0}, // Channel 4. bit 14
	                                                                  {0,0}, // Channel 4. bit 15
	                                                                  {0,0}, // Channel 4. bit 16
	                                                                  {0,0}, // Channel 4. bit 17
	                                                                  {0,0}, // Channel 4. bit 18
	                                                                  {0,0}, // Channel 4. bit 19                                                             {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 20
	                                                                  {0,0}, // Channel 4. bit 21
	                                                                  {0,0}, // Channel 4. bit 22
	                                                                  {0,0}, // Channel 4. bit 23
	                                                                  {0,0}, // Channel 4. bit 24
	                                                                  {0,0}, // Channel 4. bit 25
	                                                                  {0,0}, // Channel 4. bit 26
	                                                                  {0,0}, // Channel 4. bit 27
	                                                                  {0,0}, // Channel 4. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 29
	                                                                  {0,0}, // Channel 4. bit 30
	                                                                  {0,0}, // Channel 4. bit 31
	                                                                  {0,0}, // Channel 4. bit 32
	                                                                  {0,0}, // Channel 4. bit 33
	                                                                  {0,0}, // Channel 4. bit 34
	                                                                  {0,0}, // Channel 4. bit 35
	                                                                  {0,0}, // Channel 4. bit 36
	                                                                  {0,0}, // Channel 4. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 38
	                                                                  {0,0}, // Channel 4. bit 39
	                                                                  {0,0}, // Channel 4. bit 40
	                                                                  {0,0}, // Channel 4. bit 41
	                                                                  {0,0}, // Channel 4. bit 42
	                                                                  {0,0}, // Channel 4. bit 43
	                                                                  {0,0}, // Channel 4. bit 44
	                                                                  {0,0}, // Channel 4. bit 45
	                                                                  {0,0}, // Channel 4. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 47
	                                                                  {0,0}, // Channel 4. bit 48
	                                                                  {0,0}, // Channel 4. bit 49
	                                                                  {0,0}, // Channel 4. bit 50
	                                                                  {0,0}, // Channel 4. bit 51
	                                                                  {0,0}, // Channel 4. bit 52
	                                                                  {0,0}, // Channel 4. bit 53
	                                                                  {0,0}, // Channel 4. bit 54
	                                                                  {0,0}, // Channel 4. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 4. bit 56
	                                                                  {0,0}, // Channel 4. bit 57
	                                                                  {0,0}, // Channel 4. bit 58
	                                                                  {0,0}, // Channel 4. bit 59
	                                                                  {0,0}, // Channel 4. bit 60
	                                                                  {0,0}, // Channel 4. bit 61
	                                                                  {0,0}, // Channel 4. bit 62
	                                                                  {0,0}, // Channel 4. bit 63
	                                                                  {0,0}, // Channel 4. bit 64
	                                                                  {0,0}, // Channel 4. bit 65
	                                                                  {0,0}, // Channel 4. bit 66
	                                                                  {0,0}, // Channel 4. bit 67
	                                                                  {0,0}, // Channel 4. bit 68
	                                                                  {0,0}, // Channel 4. bit 69
	                                                                  {0,0}, // Channel 4. bit 70
	                                                                  {0,0}, // Channel 4. bit 71
	                                                                  {0,0}},// Channel 4. bit 72
	                                                                  
	                                                                  {{14,9},// Channel 5. bit 0
	                                                                  {13,9}, // Channel 5. bit 1
	                                                                  {12,9}, // Channel 5. bit 2
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 3
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 4
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 5
	                                                                  {11,9}, // Channel 5. bit 6
	                                                                  {10,9}, // Channel 5. bit 7
	                                                                  {9,9}, // Channel 5. bit 8
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 9
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 10
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 11
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 12
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 13
	                                                                  {6,8}, // Channel 5. bit 14
	                                                                  {6,9}, // Channel 5. bit 15
	                                                                  {7,9}, // Channel 5. bit 16
	                                                                  {8,9}, // Channel 5. bit 17
	                                                                  {4,7}, // Channel 5. bit 18
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 19                                                             {0,0} // 0
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 20
	                                                                  {EMPTY,EMPTY}, // Channel 5. bit 21
	                                                                  {5,9}, // Channel 5. bit 22
	                                                                  {5,8}, // Channel 5. bit 23
	                                                                  {END,END}, // Channel 5. bit 24
	                                                                  {0,0}, // Channel 5. bit 25
	                                                                  {0,0}, // Channel 5. bit 26
	                                                                  {0,0}, // Channel 5. bit 27
	                                                                  {0,0}, // Channel 5. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 5. bit 29
	                                                                  {0,0}, // Channel 5. bit 30
	                                                                  {0,0}, // Channel 5. bit 31
	                                                                  {0,0}, // Channel 5. bit 32
	                                                                  {0,0}, // Channel 5. bit 33
	                                                                  {0,0}, // Channel 5. bit 34
	                                                                  {0,0}, // Channel 5. bit 35
	                                                                  {0,0}, // Channel 5. bit 36
	                                                                  {0,0}, // Channel 5. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 5. bit 38
	                                                                  {0,0}, // Channel 5. bit 39
	                                                                  {0,0}, // Channel 5. bit 40
	                                                                  {0,0}, // Channel 5. bit 41
	                                                                  {0,0}, // Channel 5. bit 42
	                                                                  {0,0}, // Channel 5. bit 43
	                                                                  {0,0}, // Channel 5. bit 44
	                                                                  {0,0}, // Channel 5. bit 45
	                                                                  {0,0}, // Channel 5. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 5. bit 47
	                                                                  {0,0}, // Channel 5. bit 48
	                                                                  {0,0}, // Channel 5. bit 49
	                                                                  {0,0}, // Channel 5. bit 50
	                                                                  {0,0}, // Channel 5. bit 51
	                                                                  {0,0}, // Channel 5. bit 52
	                                                                  {0,0}, // Channel 5. bit 53
	                                                                  {0,0}, // Channel 5. bit 54
	                                                                  {0,0}, // Channel 5. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 5. bit 56
	                                                                  {0,0}, // Channel 5. bit 57
	                                                                  {0,0}, // Channel 5. bit 58
	                                                                  {0,0}, // Channel 5. bit 59
	                                                                  {0,0}, // Channel 5. bit 60
	                                                                  {0,0}, // Channel 5. bit 61
	                                                                  {0,0}, // Channel 5. bit 62
	                                                                  {0,0}, // Channel 5. bit 63
	                                                                  {0,0}, // Channel 5. bit 64
	                                                                  {0,0}, // Channel 5. bit 65
	                                                                  {0,0}, // Channel 5. bit 66
	                                                                  {0,0}, // Channel 5. bit 67
	                                                                  {0,0}, // Channel 5. bit 68
	                                                                  {0,0}, // Channel 5. bit 69
	                                                                  {0,0}, // Channel 5. bit 70
	                                                                  {0,0}, // Channel 5. bit 71
	                                                                  {0,0}},// Channel 5. bit 72
	                                                                  
	                                                                  {{END,END},// Channel 6. bit 0
	                                                                  {0,0}, // Channel 6. bit 1
	                                                                  {0,0}, // Channel 6. bit 2
	                                                                  {0,0}, // Channel 6. bit 3
	                                                                  {0,0}, // Channel 6. bit 4
	                                                                  {0,0}, // Channel 6. bit 5
	                                                                  {0,0}, // Channel 6. bit 6
	                                                                  {0,0}, // Channel 6. bit 7
	                                                                  {0,0}, // Channel 6. bit 8
	                                                                  {0,0}, // Channel 6. bit 9
	                                                                  {0,0}, // Channel 6. bit 10
	                                                                  {0,0}, // Channel 6. bit 11
	                                                                  {0,0}, // Channel 6. bit 12
	                                                                  {0,0}, // Channel 6. bit 13
	                                                                  {0,0}, // Channel 6. bit 14
	                                                                  {0,0}, // Channel 6. bit 15
	                                                                  {0,0}, // Channel 6. bit 16
	                                                                  {0,0}, // Channel 6. bit 17
	                                                                  {0,0}, // Channel 6. bit 18
	                                                                  {0,0}, // Channel 6. bit 19                                                             {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 20
	                                                                  {0,0}, // Channel 6. bit 21
	                                                                  {0,0}, // Channel 6. bit 22
	                                                                  {0,0}, // Channel 6. bit 23
	                                                                  {0,0}, // Channel 6. bit 24
	                                                                  {0,0}, // Channel 6. bit 25
	                                                                  {0,0}, // Channel 6. bit 26
	                                                                  {0,0}, // Channel 6. bit 27
	                                                                  {0,0}, // Channel 6. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 29
	                                                                  {0,0}, // Channel 6. bit 30
	                                                                  {0,0}, // Channel 6. bit 31
	                                                                  {0,0}, // Channel 6. bit 32
	                                                                  {0,0}, // Channel 6. bit 33
	                                                                  {0,0}, // Channel 6. bit 34
	                                                                  {0,0}, // Channel 6. bit 35
	                                                                  {0,0}, // Channel 6. bit 36
	                                                                  {0,0}, // Channel 6. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 38
	                                                                  {0,0}, // Channel 6. bit 39
	                                                                  {0,0}, // Channel 6. bit 40
	                                                                  {0,0}, // Channel 6. bit 41
	                                                                  {0,0}, // Channel 6. bit 42
	                                                                  {0,0}, // Channel 6. bit 43
	                                                                  {0,0}, // Channel 6. bit 44
	                                                                  {0,0}, // Channel 6. bit 45
	                                                                  {0,0}, // Channel 6. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 47
	                                                                  {0,0}, // Channel 6. bit 48
	                                                                  {0,0}, // Channel 6. bit 49
	                                                                  {0,0}, // Channel 6. bit 50
	                                                                  {0,0}, // Channel 6. bit 51
	                                                                  {0,0}, // Channel 6. bit 52
	                                                                  {0,0}, // Channel 6. bit 53
	                                                                  {0,0}, // Channel 6. bit 54
	                                                                  {0,0}, // Channel 6. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 6. bit 56
	                                                                  {0,0}, // Channel 6. bit 57
	                                                                  {0,0}, // Channel 6. bit 58
	                                                                  {0,0}, // Channel 6. bit 59
	                                                                  {0,0}, // Channel 6. bit 60
	                                                                  {0,0}, // Channel 6. bit 61
	                                                                  {0,0}, // Channel 6. bit 62
	                                                                  {0,0}, // Channel 6. bit 63
	                                                                  {0,0}, // Channel 6. bit 64
	                                                                  {0,0}, // Channel 6. bit 65
	                                                                  {0,0}, // Channel 6. bit 66
	                                                                  {0,0}, // Channel 6. bit 67
	                                                                  {0,0}, // Channel 6. bit 68
	                                                                  {0,0}, // Channel 6. bit 69
	                                                                  {0,0}, // Channel 6. bit 70
	                                                                  {0,0}, // Channel 6. bit 71
	                                                                  {0,0}},// Channel 6. bit 72
	                                                                  
	                                                                  {{12,5},// Channel 7. bit 0
	                                                                  {11,5}, // Channel 7. bit 1
	                                                                  {10,5}, // Channel 7. bit 2
	                                                                  {11,7}, // Channel 7. bit 3
	                                                                  {11,6}, // Channel 7. bit 4
	                                                                  {12,6}, // Channel 7. bit 5
	                                                                  {EMPTY,EMPTY}, // Channel 7. bit 6
	                                                                  {0,0}, // Channel 7. bit 7
	                                                                  {0,0}, // Channel 7. bit 8
	                                                                  {0,0}, // Channel 7. bit 9
	                                                                  {0,0}, // Channel 7. bit 10
	                                                                  {0,0}, // Channel 7. bit 11
	                                                                  {0,0}, // Channel 7. bit 12
	                                                                  {0,0}, // Channel 7. bit 13
	                                                                  {0,0}, // Channel 7. bit 14
	                                                                  {0,0}, // Channel 7. bit 15
	                                                                  {0,0}, // Channel 7. bit 16
	                                                                  {0,0}, // Channel 7. bit 17
	                                                                  {0,0}, // Channel 7. bit 18
	                                                                  {0,0}, // Channel 7. bit 19                                                             {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 20
	                                                                  {0,0}, // Channel 7. bit 21
	                                                                  {0,0}, // Channel 7. bit 22
	                                                                  {0,0}, // Channel 7. bit 23
	                                                                  {0,0}, // Channel 7. bit 24
	                                                                  {0,0}, // Channel 7. bit 25
	                                                                  {0,0}, // Channel 7. bit 26
	                                                                  {0,0}, // Channel 7. bit 27
	                                                                  {0,0}, // Channel 7. bit 28                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 29
	                                                                  {0,0}, // Channel 7. bit 30
	                                                                  {0,0}, // Channel 7. bit 31
	                                                                  {0,0}, // Channel 7. bit 32
	                                                                  {0,0}, // Channel 7. bit 33
	                                                                  {0,0}, // Channel 7. bit 34
	                                                                  {0,0}, // Channel 7. bit 35
	                                                                  {0,0}, // Channel 7. bit 36
	                                                                  {0,0}, // Channel 7. bit 37                                                           {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 38
	                                                                  {0,0}, // Channel 7. bit 39
	                                                                  {0,0}, // Channel 7. bit 40
	                                                                  {0,0}, // Channel 7. bit 41
	                                                                  {0,0}, // Channel 7. bit 42
	                                                                  {0,0}, // Channel 7. bit 43
	                                                                  {0,0}, // Channel 7. bit 44
	                                                                  {0,0}, // Channel 7. bit 45
	                                                                  {0,0}, // Channel 7. bit 46                                                            {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 47
	                                                                  {0,0}, // Channel 7. bit 48
	                                                                  {0,0}, // Channel 7. bit 49
	                                                                  {0,0}, // Channel 7. bit 50
	                                                                  {0,0}, // Channel 7. bit 51
	                                                                  {0,0}, // Channel 7. bit 52
	                                                                  {0,0}, // Channel 7. bit 53
	                                                                  {0,0}, // Channel 7. bit 54
	                                                                  {0,0}, // Channel 7. bit 55                                                              {0,0} // 0
	                                                                  {0,0}, // Channel 7. bit 56
	                                                                  {0,0}, // Channel 7. bit 57
	                                                                  {0,0}, // Channel 7. bit 58
	                                                                  {0,0}, // Channel 7. bit 59
	                                                                  {0,0}, // Channel 7. bit 60
	                                                                  {0,0}, // Channel 7. bit 61
	                                                                  {0,0}, // Channel 7. bit 62
	                                                                  {0,0}, // Channel 7. bit 63
	                                                                  {0,0}, // Channel 7. bit 64
	                                                                  {0,0}, // Channel 7. bit 65
	                                                                  {0,0}, // Channel 7. bit 66
	                                                                  {0,0}, // Channel 7. bit 67
	                                                                  {0,0}, // Channel 7. bit 68
	                                                                  {0,0}, // Channel 7. bit 69
	                                                                  {0,0}, // Channel 7. bit 70
	                                                                  {0,0}, // Channel 7. bit 71
	                                                                  {0,0}}}; // Channel 7. bit 72
	                                                                   
	                                                                   
	                                                                   #endif                                                          
	                                                          
