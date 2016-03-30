class BlockType {
    public:
        const char * texture_path;

        BlockType (const char * texture_path) {
            this->texture_path = texture_path;
        }
}

BLOCK_DIRT = BlockType("src/res/dirt.png");
