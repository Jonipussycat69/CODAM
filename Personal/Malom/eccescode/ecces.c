
int	outer_layer[3][3] = {
	{0, 0, 0},
	{0, -1, 0},
	{0, 0, 0}
};

int	middle_layer[3][3] = {
	{0, 0, 0},
	{0, -1, 0},
	{0, 0, 0}
};

int	inner_layer[3][3] = {
	{0, 0, 0},
	{0, -1, 0},
	{0, 0, 0}
};

#define A1 outer_layer[2][0]
#define A4 outer_layer[1][0]
#define A7 outer_layer[0][0]

#define B2 middle_layer[2][0]
#define B4 middle_layer[1][0]
#define B6 middle_layer[0][0]

#define C3 inner_layer[2][0]
#define C4 inner_layer[1][0]
#define C5 inner_layer[0][0]

#define D1 outer_layer[2][1]
#define D2 middle_layer[2][1]
#define D3 inner_layer[2][1]
#define D5 inner_layer[0][1]
#define D6 middle_layer[0][1]
#define D7 outer_layer[0][1]

#define E3 inner_layer[2][2]
#define E4 inner_layer[1][2]
#define E5 inner_layer[0][2]

#define F2 middle_layer[2][2]
#define F4 middle_layer[1][2]
#define F6 middle_layer[0][2]

#define G1 outer_layer[2][2]
#define G4 outer_layer[1][2]
#define G7 outer_layer[0][2]

void	reset_board(void)
{
	inner_layer[0][0] = 0;
	inner_layer[0][1] = 0;
	inner_layer[0][2] = 0;
	inner_layer[1][0] = 0;
	inner_layer[1][1] = -1;
	inner_layer[1][2] = 0;
	inner_layer[2][0] = 0;
	inner_layer[2][1] = 0;
	inner_layer[2][2] = 0;
	middle_layer[0][0] = 0;
	middle_layer[0][1] = 0;
	middle_layer[0][2] = 0;
	middle_layer[1][0] = 0;
	middle_layer[1][1] = -1;
	middle_layer[1][2] = 0;
	middle_layer[2][0] = 0;
	middle_layer[2][1] = 0;
	middle_layer[2][2] = 0;
	outer_layer[0][0] = 0;
	outer_layer[0][1] = 0;
	outer_layer[0][2] = 0;
	outer_layer[1][0] = 0;
	outer_layer[1][1] = -1;
	outer_layer[1][2] = 0;
	outer_layer[2][0] = 0;
	outer_layer[2][1] = 0;
	outer_layer[2][2] = 0;
	return ;
}
