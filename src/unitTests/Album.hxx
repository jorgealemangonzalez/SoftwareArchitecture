class Album{
public:
    std::string title(){//returns the title of the album
        return "-- Untitled --";
    }
    void title(std::string newTitle){
        return;
    }
private:
    std::string Title ;//title of the album
};