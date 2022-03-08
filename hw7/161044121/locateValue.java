public class locateValue {

    public void locateValue1D(int value){
        for (int i=0; i< row; i++)
        {
            for (int j=0; j<col; j++)
            {
                if (temp[i][j]==value)
                {
                    x=i;
                    y=j;
                }
            }
        }
    }
    
}