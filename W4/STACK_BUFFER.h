#define uchar unsigned char
#define uint  unsigned int

#define MAX_COL_SIZE 32
#define MAX_ROW_SIZE 4
#define MAX_POP_SIZE 32
#define MAX_STACK_SIZE (MAX_ROW_SIZE * MAX_COL_SIZE)


#define ROW(x) ((uint)((x)/MAX_COL_SIZE))
#define COL(x) (((x)%MAX_COL_SIZE))
#define pow2(x) (1ULL<<(x))
#define LAST_BIT(size_) ((DATA[ROW(size_)] & pow2(COL(size_)))?(1):(0))  

uint DATA[MAX_ROW_SIZE] = {0, 0, 0, 0};
uint SIZE = 0;

void PUSH_BACK(unsigned int BIT){
    if(SIZE == MAX_STACK_SIZE){
        return;
    }
    //BIT is only 0 or 1
    if( DATA[ROW(SIZE)] & pow2(COL(SIZE))){
        if( BIT == 0)
            DATA[ROW(SIZE)] -= pow2(COL(SIZE));
    }else{
        if( BIT == 1)
            DATA[ROW(SIZE)] += pow2(COL(SIZE));
    }
    ++SIZE;
}

uint POP_BACK(uint AMOUNT){
    if( AMOUNT > MAX_POP_SIZE ) return 0;
    uint t = 0;
    uint res = 0;
    for( t = 0; t < AMOUNT; t++){
        if(SIZE == 0) break;
        else --SIZE;
        res += LAST_BIT(SIZE) * pow2(t);
    }
    return res;
}