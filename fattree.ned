simple Node
{
    gates:
        input in[];
        output out[];
}

network fattree
{
    types:
        channel Channel extends ned.DelayChannel {
        		delay = 100ms;
        }
    submodules:
        Nodes[36]: Node;
    connections allowunconnected:
        for p=0..3, for e=0..1, for s=0..1{
        	Nodes[int(8*p + e*4/2 + s)].out++ --> Channel --> Nodes[int(8*p + 4*4/4 + e)].in++;
            Nodes[int(8*p + e*4/2 + s)].in++ <-- Channel <-- Nodes[int(8*p + 4*4/4 + e)].out++;
        }
        for p=0..3, for e=0..1, for a=2..3{
        	Nodes[int(8*p + 4*4/4 + e)].out++ --> Channel --> Nodes[int(8*p + 4*4/4 + a)].in++;
            Nodes[int(8*p + 4*4/4 + e)].in++ <-- Channel <-- Nodes[int(8*p + 4*4/4 + a)].out++;
        }
        for p=0..3, for a=0..1, for c=0..1{
        	Nodes[int(8*p + 4*4/4 + 2 + a)].out++ --> Channel --> Nodes[int(a*4/2 + c + 16 + 16)].in++;
            Nodes[int(8*p + 4*4/4 + 2 + a)].in++ <-- Channel <-- Nodes[int(a*4/2 + c + 16 + 16)].out++;
        }  
}