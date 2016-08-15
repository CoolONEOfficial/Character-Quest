#include "gmapcategory.h"

GMapCategory::GMapCategory(float oLuck)
{
    // Luck
    luck = oLuck;
}

GMapCategory::~GMapCategory()
{
    // Delete objects
    for(size_t mObj = 0; mObj < objects.size(); mObj++)
    {
        delete objects[mObj];
    }
}

GMapObject *GMapCategory::generateObject()
{
    // Generate object

    GMapObject *gObject = new GMapObject;

    // Set real luck
    setObjectsRealLuck();

    float random = randf(100.0);

    // Select object
    float saveLuck = 0;
    for(size_t mObj = 0; mObj < objects.size(); mObj++)
    {
        if(random > saveLuck &&
           random < saveLuck + objects[mObj]->realLuck)
        {
            // Return object
            gObject = objects[mObj];
            break;
        }
        else
        {
            // Next object
            saveLuck += objects[mObj]->realLuck;
        }
    }

    return gObject;
}

void GMapCategory::setObjectsRealLuck()
{
    // Set objects real luck
    for(size_t f = 0; f < objects.size(); f++)
    {
        objects[f]->setRealLuck(objects.size());
    }
}

void GMapCategory::addObject(GMapObject *aObject, string name)
{
    // Add id
    size_t objectsSize = objectsId.size();
    objectsId[name] = objectsSize;

    // Add object
    objects.push_back(new GMapObject);
    objects[objectsId[name]] = aObject;
}

void GMapCategory::setRealLuck(float allLuck)
{
    realLuck = luck * (100.0 / allLuck);
}

