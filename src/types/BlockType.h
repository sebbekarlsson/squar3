class BlockType {
    public:
        const char * texture_path;

        BlockType (const char * texture_path) {
            this->texture_path = texture_path;
        }
};

BlockType BLOCK_GRASS = BlockType("src/res/grass.png");
BlockType BLOCK_DIRT = BlockType("src/res/dirt.png");
BlockType BLOCK_COBBLE = BlockType("src/res/cobble.png");
BlockType BLOCK_AIR = BlockType("");
