simple Hw
{
    parameters:
        @display("i=block/routing");
        double xpos;
        double ypos;
        @display("p=$xpos,$ypos");
        
    gates:
        inout gate[]; 
}

network hw1
{
    parameters:
        @display("bgb=600");
        node[0].xpos = 100;
        node[0].ypos = 100;
        node[1].xpos = 100;
        node[1].ypos = 200;
        node[2].xpos = 100;
        node[2].ypos = 300;
        node[3].xpos = 100;
        node[3].ypos = 400;
        node[4].xpos = 100;
        node[4].ypos = 500;
        node[5].xpos = 300;
        node[5].ypos = 100;
        node[6].xpos = 300;
        node[6].ypos = 200;
        node[7].xpos = 300;
        node[7].ypos = 300;
        node[8].xpos = 300;
        node[8].ypos = 400;
        node[9].xpos = 300;
        node[9].ypos = 500;
    types:
        channel Channel extends ned.DelayChannel {
            delay = 100ms;
        }
    submodules:
        node[10]: Hw;
        
    connections allowunconnected:
      	node[0].gate++ <--> Channel <-->node[1].gate++;
      	node[1].gate++ <--> Channel <-->node[2].gate++;
      	node[2].gate++ <--> Channel <-->node[3].gate++;
      	node[3].gate++ <--> Channel <-->node[4].gate++;
      	node[5].gate++ <--> Channel <-->node[6].gate++;
      	node[6].gate++ <--> Channel <-->node[7].gate++;
      	node[7].gate++ <--> Channel <-->node[8].gate++;
      	node[8].gate++ <--> Channel <-->node[9].gate++;
      	node[2].gate++ <--> Channel <-->node[7].gate++;
}