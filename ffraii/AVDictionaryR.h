#pragma once

extern "C" {
#include <libavutil/dict.h>
}

namespace ffraii {
    class AVDictionaryR final {
    public:
        using WrappedType = AVDictionary*;

        AVDictionaryR();

        explicit AVDictionaryR(WrappedType resource);
        ~AVDictionaryR();

        // Resource types can not be copied

        AVDictionaryR(const AVDictionaryR&) = delete;
        AVDictionaryR& operator=(const AVDictionaryR&) = delete;

        // But can be moved

        AVDictionaryR(AVDictionaryR&& other);
        AVDictionaryR& operator=(AVDictionaryR&& other);

        // returns true iff wrapped resource is valid
        explicit operator bool() const;

        // returns true iff wrapped resource is valid
        bool ok() const;

        operator WrappedType() const;

        WrappedType unwrap() const;

        // Force releasing the resource
        void release();

        WrappedType* p_value();

        const WrappedType* p_value() const;

        WrappedType operator->() {
            return m_resource;
        }

        const WrappedType operator->() const {
            return m_resource;
        }


        static const WrappedType s_invalidValue;

    private:
        WrappedType m_resource;
    };
}
