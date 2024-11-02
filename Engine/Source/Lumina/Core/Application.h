#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#include "Core.h"

namespace Lumina
{
    class LUMINA_API FApplication
    {
        public:
        FApplication();
        virtual ~FApplication();

        void Run();
    
        protected:
    
        private:
    
    };

    // To be defined in the Sandbox application
    FApplication* CreateApplication();
}

#endif /* CORE_APPLICATION_H */