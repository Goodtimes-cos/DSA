# Huffman implementation in Python
"""
Complexity O(n log n)

Huffman coding is a technique developed to compress data to reduce
it's size without loss of data.

Huffman encoding is done in the following way:
1 - Calculate the frequency of each character in the string
2 - Sort the characters in increasing order of the frequency. These
are stored in a priority queue
3 - Make a unique character as a leaf node
4 - Create an empty node, z. Assign the minimum frequency to the left
child of z and assign the second minimum to the right child of z.
Set the value of z to be the sum of the above two minimum frequencies.
5 - Remove these two minimum frequencies from Q and add the sum into
the list of frequencies
6 - Insert node z into the tree
7 - Repeat steps 3 to 5 for all the characters
8 - For each non-leaf node, assign 0 to the left edge and 1 to the
right edge.
"""

string = 'BCAADDDCCACACAC'


# Creating tree nodes
class NodeTree(object):

    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

    def children(self):
        return (self.left, self.right)

    def nodes(self):
        return (self.left, self.right)

    def __str__(self):
        return '%s_%s' % (self.left, self.right)


# Main function implementing huffman coding
def huffman_code_tree(node, left=True, binString=''):
    if type(node) is str:
        return {node: binString}
    (l, r) = node.children()
    d = dict()
    d.update(huffman_code_tree(l, True, binString + '0'))
    d.update(huffman_code_tree(r, False, binString + '1'))
    return d


# Calculating frequency
freq = {}
for c in string:
    if c in freq:
        freq[c] += 1
    else:
        freq[c] = 1

freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)

nodes = freq

while len(nodes) > 1:
    (key1, c1) = nodes[-1]
    (key2, c2) = nodes[-2]
    nodes = nodes[:-2]
    node = NodeTree(key1, key2)
    nodes.append((node, c1 + c2))

    nodes = sorted(nodes, key=lambda x: x[1], reverse=True)

huffmanCode = huffman_code_tree(nodes[0][0])

print(' Char | Huffman code ')
print('----------------------')
for (char, frequency) in freq:
    print(' %-4r |%12s' % (char, huffmanCode[char]))