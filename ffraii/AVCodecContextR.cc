#include "AVCodecContextR.h"

namespace ffraii {
    const AVCodecContextR::WrappedType AVCodecContextR::s_invalidValue = nullptr;

    AVCodecContextR::AVCodecContextR()
    : m_resource(s_invalidValue)
    {}

    AVCodecContextR::AVCodecContextR(WrappedType resource)
    : m_resource(resource)
    {}

    AVCodecContextR::~AVCodecContextR(){
        release();
    }

    void AVCodecContextR::release(){
        if (m_resource != s_invalidValue){
            avcodec_free_context(&m_resource);
            m_resource = s_invalidValue;
        }
    }

    AVCodecContextR::AVCodecContextR(AVCodecContextR&& other)
    : m_resource(other.m_resource)
    {
        other.m_resource = s_invalidValue;
    }

    AVCodecContextR& AVCodecContextR::operator=(AVCodecContextR&& other){
        if (&other != this){
            release();
            m_resource = other.m_resource;
            other.m_resource = s_invalidValue;
        }

        return *this;
    }

    // returns true iff wrapped resource is valid
    AVCodecContextR::operator bool() const {
        return ok();
    }

    // returns true iff wrapped resource is valid
    bool AVCodecContextR::ok() const{
        return m_resource != s_invalidValue;
    }

    AVCodecContextR::operator WrappedType() const{
        return m_resource;
    }

    AVCodecContextR::WrappedType AVCodecContextR::unwrap() const {
        return m_resource;
    }

    AVCodecContextR::WrappedType* AVCodecContextR::p_value(){
        return &m_resource;
    }

    const AVCodecContextR::WrappedType* AVCodecContextR::p_value() const{
        return &m_resource;
    }
}
