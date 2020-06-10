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
message HwMsg2
{
    int source;
    int trace[200];
    int traceCount = 0;
    int nodeCount = 100;
    
    double xpos;
    double ypos;
    
    int src[10000];
    int des[10000];
    double distances[10000];
    int gate[10000];
    int preGate = -1;
    int size = 0;
}