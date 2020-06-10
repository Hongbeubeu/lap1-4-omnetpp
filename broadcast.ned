simple BroadCast
{
    gates:
        input in[];
        output out[];
}

network net
{
    submodules:
        node[5]: BroadCast;
    connections:
        node[4].out++ --> {delay = 100ms;} --> node[0].in++;
        node[4].in++ <-- {delay = 100ms;} <-- node[0].out++;
        for i=0..3{
            node[i].out++ --> {delay = 100ms;} --> node[i+1].in++;
            node[i].in++ <-- {delay = 100ms;} <-- node[i+1].out++;
        }
}
        