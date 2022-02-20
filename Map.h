#include <iostream>

using namespace std;

template <class Key_Type, class Val_Type> class Map {
    
    private:
        Key_Type* keys;
        Val_Type* values;
        int size;
    
    public:
        Map() {
            keys = NULL;
            values = NULL;
            size = 0;
        }

        Map(Map& src) {
            Key_Type* tempKeys = new Key_Type[src.size];
            Val_Type* tempVals = new Val_Type[src.size];

            for (int i = 0; i < src.size; i++)
            {
                tempKeys[i] = src.keys[i];
                tempVals[i] = src.values[i];
            }
            this->size = src.size;
            this->keys = tempKeys;
            this->values = tempVals;
            
        }

        ~Map() {
            if(keys)
                delete[] keys;
            if(values)
                delete[] values;
        }

        void add(Key_Type key, Val_Type value) {
            if(!find(key)) {
                Key_Type* tempKeys = new Key_Type[size+1]();
                Val_Type* tempVals = new Val_Type[size+1]();

                for (int i = 0; i < this->size; i++)
                {
                    tempKeys[i] = this->keys[i];
                    tempVals[i] = this->values[i];
                }
                tempKeys[size] = key;
                tempVals[size] = value;

                clear();
                this->keys = tempKeys;
                this->values = tempVals;
                this->size++;

                

            }
            else {
                cout<<"This key is already taken"<<endl;
            }
        }

        Val_Type* find(Key_Type key) {
            for (int i = 0; i < size; i++)
            {
                if(keys[i] == key) {
                    return &values[i];
                }
            }
            return NULL;   
        }

        Map& operator=(Map& src) {
            if (this == &src)
                return *this;
            
            if (size!=0)
                clear();
            
            Map<Key_Type, Val_Type> map(src);

            this->keys = map.keys;
            this->values = map.values;
            this->size = map.size;

            map.keys = NULL;
            map.values = NULL;
            
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Map& map) {
            for (int i = 0; i < map.size; i++)
            {
                os<<"{"<<map.keys[i]<<" : "<<map.values[i]<<"}\n";
            }
            return os;            
        }
        
        void clear() {
            //if(keys)
                delete[] keys;
            //if(values)
                delete[] values;
        }

};

