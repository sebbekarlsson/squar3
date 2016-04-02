class BlockType {
    public:
        EasyImage * image;

        BlockType (EasyImage * image) {
            this->image = image;
        }
};

SDLImageLoader IMGLoader = SDLImageLoader();

BlockType BLOCK_GRASS = BlockType(IMGLoader.load("src/res/grass.png"));
BlockType BLOCK_DIRT = BlockType(IMGLoader.load("src/res/dirt.png"));
BlockType BLOCK_COBBLE = BlockType(IMGLoader.load("src/res/cobble.png"));
BlockType BLOCK_STONE = BlockType(IMGLoader.load("src/res/stone.png"));
BlockType BLOCK_AIR = BlockType(NULL);
