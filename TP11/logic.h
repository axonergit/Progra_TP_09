void koch(unsigned int orderN, unsigned int side_Length);
void recursive_koch(unsigned int orderN, unsigned int side_Length,int rotation1, int rotation2, segment_t seg);

void close_Base_Triangle();


typedef struct {
    unsigned int x;
    unsigned int y;
} point_t;
typedef struct {
    point_t initial_Point;
    point_t final_Point;
} segment_t;