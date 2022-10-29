export function dfs(grid, startNode, endNode, diagonal) 
{
    const visitedNodesInOrder = []; // array of nodes
    dfsRecursive(grid, startNode, endNode, visitedNodesInOrder, diagonal); // call the recursive function
    return visitedNodesInOrder; // return the array of nodes
}

function dfsRecursive(grid, node, endNode, visitedNodesInOrder, diagonal) 
{
    node.isVisited = true; // set the node to visited
    visitedNodesInOrder.push(node); // add the node to the array
    if (node === endNode) return true; // if the node is the end node, return true
    const side_nodes_x = [0, 0, 1, -1]; // array of x values for side nodes
    const side_nodes_y = [1, -1, 0, 0]; // array of y values for side nodes
    for (let i = 0; i < 4; ++i) // loop through the side nodes
    { 
        const { col, row } = node; // get the col and row of the node
        const new_x = row + side_nodes_x[i]; // get the new x value
        const new_y = col + side_nodes_y[i]; // get the new y value
        if (!(new_x >= 0 && new_y >= 0 && new_x < grid.length && new_y < grid[0].length)) continue; 
        // if the new x and y values are out of bounds, continue
        const neighbor = grid[new_x][new_y]; // get the neighbor node
        if (neighbor.isVisited === true || neighbor.isWall === true) continue; // if the neighbor is visited or a wall, continue
        neighbor.previousNode = node; // set the neighbor's previous node to the current node
        if (dfsRecursive(grid, neighbor, endNode, visitedNodesInOrder, diagonal)) return true; // if the neighbor is the end node, return true
    }
    if (diagonal === true) 
    {
        const diagonal_nodes_x = [1, 1, -1, -1]; // array of x values for diagonal nodes
        const diagonal_nodes_y = [1, -1, 1, -1]; // array of y values for diagonal nodes

        for (let i = 0; i < 4; ++i) 
        {
            const { col, row } = node; // get the col and row of the node
            const new_x = row + diagonal_nodes_x[i]; // get the new x value
            const new_y = col + diagonal_nodes_y[i]; // get the new y value 
            if (!(new_x >= 0 && new_y >= 0 && new_x < grid.length && new_y < grid[0].length)) continue; 
            // if the new x and y values are out of bounds, continue
            const neighbor = grid[new_x][new_y]; // get the neighbor node
            if (neighbor.isVisited === true || neighbor.isWall === true) continue; // if the neighbor is visited or a wall, continue
            neighbor.previousNode = node; // set the neighbor's previous node to the current node
            if (dfsRecursive(grid, neighbor, endNode, visitedNodesInOrder, diagonal)) return true; // if the neighbor is the end node, return true
        }
    }
    return false;

}