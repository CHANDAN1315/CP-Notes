/*
  Condition for BST : left node(value) < root node(value) < right node(value)
  - condition hold for every subtree i.e the entire left subtree should also be BST and entire right subtree should also be BST
  Eg:          8
           /      \
          3        10
        /   \       \
       1     6       14
            /  \     /
           4    7   13

  - In BST idealy ther should not be dublicates but just in case there are then count the frequency and store (node, frequency)
  - Why BST
    since we know that the worst time of BT can be o(height of BT) but in BST most of the time it will be TC: log(height of BT)
*/
