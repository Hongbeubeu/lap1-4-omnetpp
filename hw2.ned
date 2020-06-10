//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

simple Hw2
{
    parameters:
        @display("i=block/routing");
        double xpos;
        double ypos;
        @display("p=$xpos,$ypos");
        
        int start;
        int finish;
        
    gates:
        input in[];    
        output out[];  
}

network hw2
{
    parameters:
        @display("bgb=800");
        node[0].xpos = 0;
        node[10].xpos = 0;
        node[20].xpos = 0;
        node[30].xpos = 0;
        node[40].xpos = 0;
        node[50].xpos = 0;
        node[60].xpos = 0;
        node[70].xpos = 0;
        node[80].xpos = 0;
        node[90].xpos = 0;
        
        node[1].xpos = 70;
        node[11].xpos = 70;
        node[21].xpos = 70;
        node[31].xpos = 70;
        node[41].xpos = 70;
        node[51].xpos = 70;
        node[61].xpos = 70;
        node[71].xpos = 70;
        node[81].xpos = 70;
        node[91].xpos = 70;
        
        node[2].xpos = 140;
        node[12].xpos = 140;
        node[22].xpos = 140;
        node[32].xpos = 140;
        node[42].xpos = 140;
        node[52].xpos = 140;
        node[62].xpos = 140;
        node[72].xpos = 140;
        node[82].xpos = 140;
        node[92].xpos = 140;
        
        node[3].xpos = 210;
        node[13].xpos = 210;
        node[23].xpos = 210;
        node[33].xpos = 210;
        node[43].xpos = 210;
        node[53].xpos = 210;
        node[63].xpos = 210;
        node[73].xpos = 210;
        node[83].xpos = 210;
        node[93].xpos = 210;
        
        node[4].xpos = 280;
        node[14].xpos = 280;
        node[24].xpos = 280;
        node[34].xpos = 280;
        node[44].xpos = 280;
        node[54].xpos = 280;
        node[64].xpos = 280;
        node[74].xpos = 280;
        node[84].xpos = 280;
        node[94].xpos = 280;
        
        
       
        node[5].xpos = 350;
        node[15].xpos = 350;
        node[25].xpos = 350;
        node[35].xpos = 350;
        node[45].xpos = 350;
        node[55].xpos = 350;
        node[65].xpos = 350;
        node[75].xpos = 350;
        node[85].xpos = 350;
        node[95].xpos = 350;
        
       
        node[6].xpos = 420;
        node[16].xpos = 420;
        node[26].xpos = 420;
        node[36].xpos = 420;
        node[46].xpos = 420;
        node[56].xpos = 420;
        node[66].xpos = 420;
        node[76].xpos = 420;
        node[86].xpos = 420;
        node[96].xpos = 420;
        
        node[7].xpos = 490;
        node[17].xpos = 490;
        node[27].xpos = 490;
        node[37].xpos = 490;
        node[47].xpos = 490;
        node[57].xpos = 490;
        node[67].xpos = 490;
        node[77].xpos = 490;
        node[87].xpos = 490;
        node[97].xpos = 490;
        
        node[8].xpos = 560;
        node[18].xpos = 560;
        node[28].xpos = 560;
        node[38].xpos = 560;
        node[48].xpos = 560;
        node[58].xpos = 560;
        node[68].xpos = 560;
        node[78].xpos = 560;
        node[88].xpos = 560;
        node[98].xpos = 560;
       
        node[9].xpos = 630;
        node[19].xpos = 630;
        node[29].xpos = 630;
        node[39].xpos = 630;
        node[49].xpos = 630;
        node[59].xpos = 630;
        node[69].xpos = 630;
        node[79].xpos = 630;
        node[89].xpos = 630;
        node[99].xpos = 630;
        
        node[0].ypos = 0;
        node[1].ypos = 0;
        node[2].ypos = 0;
        node[3].ypos = 0;
        node[4].ypos = 0;
        node[5].ypos = 0;
        node[6].ypos = 0;
        node[7].ypos = 0;
        node[8].ypos = 0;
        node[9].ypos = 0;
        
        node[10].ypos = 70;
        node[11].ypos = 70;
        node[12].ypos = 70;
        node[13].ypos = 70;
        node[14].ypos = 70;
        node[15].ypos = 70;
        node[16].ypos = 70;
        node[17].ypos = 70;
        node[18].ypos = 70;
        node[19].ypos = 70;
        
        node[20].ypos = 140;
        node[21].ypos = 140;
        node[22].ypos = 140;
        node[23].ypos = 140;
        node[24].ypos = 140;
        node[25].ypos = 140;
        node[26].ypos = 140;
        node[27].ypos = 140;
        node[28].ypos = 140;
        node[29].ypos = 140;
        
        node[30].ypos = 210;
        node[31].ypos = 210;
        node[32].ypos = 210;
        node[33].ypos = 210;
        node[34].ypos = 210;
        node[35].ypos = 210;
        node[36].ypos = 210;
        node[37].ypos = 210;
        node[38].ypos = 210;
        node[39].ypos = 210;
        
        node[40].ypos = 280;
        node[41].ypos = 280;
        node[42].ypos = 280;
        node[43].ypos = 280;
        node[44].ypos = 280;
        node[45].ypos = 280;
        node[46].ypos = 280;
        node[47].ypos = 280;
        node[48].ypos = 280;
        node[49].ypos = 280;
        
        node[50].ypos = 350;
        node[51].ypos = 350;
        node[52].ypos = 350;
        node[53].ypos = 350;
        node[54].ypos = 350;
        node[55].ypos = 350;
        node[56].ypos = 350;
        node[57].ypos = 350;
        node[58].ypos = 350;
        node[59].ypos = 350;
        
        node[60].ypos = 420;
        node[61].ypos = 420;
        node[62].ypos = 420;
        node[63].ypos = 420;
        node[64].ypos = 420;
        node[65].ypos = 420;
        node[66].ypos = 420;
        node[67].ypos = 420;
        node[68].ypos = 420;
        node[69].ypos = 420;
       
       	node[70].ypos = 490;
        node[71].ypos = 490;
        node[72].ypos = 490;
        node[73].ypos = 490;
        node[74].ypos = 490;
        node[75].ypos = 490;
        node[76].ypos = 490;
        node[77].ypos = 490;
        node[78].ypos = 490;
        node[79].ypos = 490; 
        
        node[80].ypos = 560;
        node[81].ypos = 560;
        node[82].ypos = 560;
        node[83].ypos = 560;
        node[84].ypos = 560;
        node[85].ypos = 560;
        node[86].ypos = 560;
        node[87].ypos = 560;
        node[88].ypos = 560;
        node[89].ypos = 560;
        
        node[90].ypos = 630;
        node[91].ypos = 630;
        node[92].ypos = 630;
        node[93].ypos = 630;
        node[94].ypos = 630;
        node[95].ypos = 630;
        node[96].ypos = 630;
        node[97].ypos = 630;
        node[98].ypos = 630;
        node[99].ypos = 630;
    types:
        channel Channel extends ned.DelayChannel {
            delay = 100ms;
        }
    submodules:
        node[100]: Hw2;
	connections:
        for i=0..99, for j=0..99 {
            node[i].out++ --> Channel --> node[j].in++
            	if i!=j && sqrt((node[i].xpos-node[j].xpos)*(node[i].xpos-node[j].xpos)+(node[i].ypos-node[j].ypos)*(node[i].ypos-node[j].ypos)) <= 100;
        }
}
