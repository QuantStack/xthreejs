#ifndef XTHREE_INSTANCED_BUFFER_ATTRIBUTE_HPP
#define XTHREE_INSTANCED_BUFFER_ATTRIBUTE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xbuffer_attribute_autogen.hpp"

namespace xthree
{
    //
    // instanced_buffer_attribute declaration
    //

    template<class D>
    class xinstanced_buffer_attribute : public xbuffer_attribute<D>
    {
    public:

        using base_type = xbuffer_attribute<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(int, derived_type, meshPerAttribute, 1);


    protected:

        xinstanced_buffer_attribute();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using instanced_buffer_attribute = xw::xmaterialize<xinstanced_buffer_attribute>;

    using instanced_buffer_attribute_generator = xw::xgenerator<xinstanced_buffer_attribute>;

    //
    // instanced_buffer_attribute implementation
    //

    inline void set_patch_from_property(const decltype(instanced_buffer_attribute::array)& property,
                                        xeus::xjson& patch,
                                        xeus::buffer_sequence& buffers)
    {
        xeus::xjson j = {
            {"shape", property().shape()},
            {"dtype", "float32"},
            {"buffer", xw::xbuffer_reference_prefix() + std::to_string(buffers.size())}
        };
        patch[property.name()] = std::move(j);
        // TODO raw_data -> data upon release 0.16 for xtensor
        buffers.emplace_back(property().raw_data(), 4 * property().size());
    }

    inline void set_property_from_patch(decltype(instanced_buffer_attribute::array)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(instanced_buffer_attribute::array)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }
    
    inline void set_patch_from_property(const decltype(instanced_buffer_attribute_generator::array)& property,
                                        xeus::xjson& patch,
                                        xeus::buffer_sequence& buffers)
    {
        xeus::xjson j = {
            {"shape", property().shape()},
            {"dtype", "float32"},
            {"buffer", xw::xbuffer_reference_prefix() + std::to_string(buffers.size())}
        };
        patch[property.name()] = std::move(j);
        // TODO raw_data -> data upon release 0.16 for xtensor
        buffers.emplace_back(property().raw_data(), 4 * property().size());
    }

    inline void set_property_from_patch(decltype(instanced_buffer_attribute_generator::array)& property,
                                        const xeus::xjson& patch,
                                        const xeus::buffer_sequence& buffers)
    {
        using value_type = typename decltype(instanced_buffer_attribute_generator::array)::value_type;
        std::size_t index = xw::buffer_index(patch[property.name()].template get<std::string>());
        const auto& buffer = buffers[index];
        property = xt::adapt(const_cast<float*>(static_cast<const float*>(buffer.data())),
                             buffer.size() / 4, xt::no_ownership(),
                             std::array<std::size_t, 1>{2});
    }


    template <class D>
    inline void xinstanced_buffer_attribute<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(meshPerAttribute, state, buffers);
    }

    template <class D>
    inline void xinstanced_buffer_attribute<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(meshPerAttribute, patch, buffers);
    }

    template <class D>
    inline xinstanced_buffer_attribute<D>::xinstanced_buffer_attribute()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinstanced_buffer_attribute<D>::set_defaults()
    {
        this->_model_name() = "InstancedBufferAttributeModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xinstanced_buffer_attribute>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xinstanced_buffer_attribute>>;
    extern template class xw::xgenerator<xthree::xinstanced_buffer_attribute>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xinstanced_buffer_attribute>>;
#endif

#endif