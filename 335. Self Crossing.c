bool isSelfCrossing(int* x, int xSize)
{
    int border[4] = {1000, 1000, -1000, -1000};
    int borderTmp[4] = {1000, 1000, -1000, -1000};
    //printf("%d %d", border[0], border[3]);
    int posx = 0, posy = 0;
    for(int i = 0; i < xSize; i++)
    {
        switch(i % 4)
        {
            case 0:
            {
                if(posx >= border[2] && posx <= border[0] && i > 3)
                {
                    if((posy - border[1]) * (posy + x[i] - border[1]) <= 0 || ((i > 4 || posx == border[0]) && posy != border[3] && posy + x[i] == border[3]) || ((i > 4 || posx == border[0]) && (posy - border[3]) * (posy + x[i] - border[3]) < 0))
                        return true;
                }
                border[2] = borderTmp[2];
                borderTmp[3] = posy;
                posy += x[i];
                break;
            }
            case 1:
            {
                if(posy >= border[3] && posy <= border[1] && i > 3)
                {
                    if((posx - border[0]) * (posx - x[i] - border[0]) < 0 || (posx != border[0] && posx - x[i] == border[0]) || (posx != border[2] && posx - x[i] == border[2]) || (posx - border[2]) * (posx - x[i] - border[2]) < 0)
                        return true;
                }
                border[3] = borderTmp[3];
                borderTmp[0] = posx;
                posx -= x[i];
                break;
            }
            case 2:
            {
                if(posx >= border[2] && posx <= border[0] && i > 3)
                {
                    if((posy - border[1]) * (posy - x[i] - border[1]) < 0 || (posy != border[1] && posy - x[i] == border[1]) || (posy != border[3] && posy - x[i] == border[3]) || (posy - border[3]) * (posy - x[i] - border[3]) < 0)
                        return true;
                }
                border[0] = borderTmp[0];
                borderTmp[1] = posy;
                posy -= x[i];
                break;
            }
            case 3:
            {
                if(posy >= border[3] && posy <= border[1])
                {
                    if((posx - border[0]) * (posx + x[i] - border[0]) < 0 || (posx != border[0] && posx + x[i] == border[0]) || (posx - border[2]) * (posx + x[i] - border[2]) < 0 || (posx != border[2] && posx + x[i] == border[2]))
                        return true;
                }
                border[1] = borderTmp[1];
                borderTmp[2] = posx;
                posx += x[i];
                break;
            }
        }
    }
    return false;
}