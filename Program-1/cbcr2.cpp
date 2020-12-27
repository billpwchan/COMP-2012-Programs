void cbr(Large_Obj& LO) { cout << LO.height; }
void cbcr(const Large_Obj& LO) { cout << LO.height; }

int main() 
{
    Large_Obj dinosaur(50);
    const Large_Obj rocket(100);

    // Which of the following give(s) compilation error?
    cbr(dinosaur);
    cbcr(dinosaur);
    cbr(rocket); 
    cbcr(rocket);
}
