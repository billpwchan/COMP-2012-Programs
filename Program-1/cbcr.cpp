void cbr(Large_Obj& LO) { LO.height += 10; } // Fine

void cbcr(const Large_Obj& LO) { LO.height += 10; } // Error!
