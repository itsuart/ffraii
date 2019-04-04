#include "AVDictionaryR.h"

namespace ffraii {
    const AVDictionaryR::WrappedType AVDictionaryR::s_invalidValue = nullptr;

    AVDictionaryR::AVDictionaryR()
    : m_resource(s_invalidValue)
    {}

    AVDictionaryR::AVDictionaryR(WrappedType resource)
    : m_resource(resource)
    {}

    AVDictionaryR::~AVDictionaryR(){
        release();
    }

    void AVDictionaryR::release(){
        if (m_resource != s_invalidValue){
            av_dict_free(&m_resource);
            m_resource = s_invalidValue;
        }
    }

    AVDictionaryR::AVDictionaryR(AVDictionaryR&& other)
    : m_resource(other.m_resource)
    {
        other.m_resource = s_invalidValue;
    }

    AVDictionaryR& AVDictionaryR::operator=(AVDictionaryR&& other){
        if (&other != this){
            release();
            m_resource = other.m_resource;
            other.m_resource = s_invalidValue;
        }

        return *this;
    }

    // returns true iff wrapped resource is valid
    AVDictionaryR::operator bool() const {
        return ok();
    }

    // returns true iff wrapped resource is valid
    bool AVDictionaryR::ok() const{
        return m_resource != s_invalidValue;
    }

    AVDictionaryR::operator WrappedType() const{
        return m_resource;
    }

    AVDictionaryR::WrappedType AVDictionaryR::unwrap() const {
        return m_resource;
    }

    AVDictionaryR::WrappedType* AVDictionaryR::p_value(){
        return &m_resource;
    }

    const AVDictionaryR::WrappedType* AVDictionaryR::p_value() const{
        return &m_resource;
    }
}
