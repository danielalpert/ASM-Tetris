.data




GenTetromino STRUCT
	mino Img<>
GenTetromino ends

Point STRUCT
	x DWORD 0
	y DWORD 0
Point ends

Tetromino STRUCT
	general GenTetromino<>
	pos Point<>
Tetromino ends

redMinoLoc byte "Minos/Red.bmp",0
greenMinoLoc byte "Minos/Green.bmp",0
blueMinoLoc byte "Minos/Blue.bmp",0
yellowMinoLoc byte "Minos/Yellow.bmp",0
pinkMinoLoc byte "Minos/Pink.bmp",0
orangeMinoLoc byte "Minos/Orange.bmp",0
purpleMinoLoc byte "Minos/Purple.bmp",0

oTetr GenTetromino<>
iTetr GenTetromino<>
tTetr GenTetromino<>
lTetr GenTetromino<>
jTetr GenTetromino<>
sTetr GenTetromino<>
zTetr GenTetromino<>