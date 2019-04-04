#include "AVFormatContextR.h"

namespace ffraii {
    const AVFormatContextR::WrappedType AVFormatContextR::s_invalidValue = nullptr;

    AVFormatContextR::AVFormatContextR()
    : m_resource(s_invalidValue)
    {}

    AVFormatContextR::AVFormatContextR(WrappedType resource)
    : m_resource(resource)
    {}

    AVFormatContextR::~AVFormatContextR(){
        release();
    }

    void AVFormatContextR::release(){
        if (m_resource != s_invalidValue){
            avformat_free_context(m_resource);
            m_resource = s_invalidValue;
        }
    }

    AVFormatContextR::AVFormatContextR(AVFormatContextR&& other)
    : m_resource(other.m_resource)
    {
        other.m_resource = s_invalidValue;
    }

    AVFormatContextR& AVFormatContextR::operator=(AVFormatContextR&& other){
        if (&other != this){
            release();
            m_resource = other.m_resource;
            other.m_resource = s_invalidValue;
        }

        return *this;
    }

    // returns true iff wrapped resource is valid
    AVFormatContextR::operator bool() const {
        return ok();
    }

    // returns true iff wrapped resource is valid
    bool AVFormatContextR::ok() const{
        return m_resource != s_invalidValue;
    }

    AVFormatContextR::operator WrappedType() const{
        return m_resource;
    }

    AVFormatContextR::WrappedType AVFormatContextR::unwrap() const {
        return m_resource;
    }

    AVFormatContextR::WrappedType* AVFormatContextR::p_value(){
        return &m_resource;
    }

    const AVFormatContextR::WrappedType* AVFormatContextR::p_value() const{
        return &m_resource;
    }
}
