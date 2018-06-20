#ifndef XTHREE_PICKER_HPP
#define XTHREE_PICKER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xcontrols_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // picker declaration
    //

    template<class D>
    class xpicker : public xcontrols<D>
    {
    public:

        using base_type = xcontrols<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, event, "click");
        XPROPERTY(bool, derived_type, all, false);
        XPROPERTY(xtl::xoptional<double>, derived_type, distance);
        XPROPERTY(vector3, derived_type, point, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, face, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, faceNormal, vector3({0,0,0}));
        XPROPERTY(std::vector<std::vector<double>>, derived_type, faceVertices, std::vector<std::vector<double>>({}));
        XPROPERTY(int, derived_type, faceIndex, 0);
        XPROPERTY(std::vector<double>, derived_type, modifiers, std::vector<double>({}));
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, object);
        XPROPERTY(std::vector<double>, derived_type, picked, std::vector<double>({}));
        XPROPERTY(vector2, derived_type, uv, vector2({0,0}));
        XPROPERTY(std::vector<double>, derived_type, indices, std::vector<double>({}));


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xpicker();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using picker = xw::xmaterialize<xpicker>;

    using picker_generator = xw::xgenerator<xpicker>;

    //
    // picker implementation
    //


    template <class D>
    inline void xpicker<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(event, state, buffers);
        xw::set_patch_from_property(all, state, buffers);
        xw::set_patch_from_property(distance, state, buffers);
        xw::set_patch_from_property(point, state, buffers);
        xw::set_patch_from_property(face, state, buffers);
        xw::set_patch_from_property(faceNormal, state, buffers);
        xw::set_patch_from_property(faceVertices, state, buffers);
        xw::set_patch_from_property(faceIndex, state, buffers);
        xw::set_patch_from_property(modifiers, state, buffers);
        xw::set_patch_from_property(object, state, buffers);
        xw::set_patch_from_property(picked, state, buffers);
        xw::set_patch_from_property(uv, state, buffers);
        xw::set_patch_from_property(indices, state, buffers);
    }

    template <class D>
    inline void xpicker<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(event, patch, buffers);
        xw::set_property_from_patch(all, patch, buffers);
        xw::set_property_from_patch(distance, patch, buffers);
        xw::set_property_from_patch(point, patch, buffers);
        xw::set_property_from_patch(face, patch, buffers);
        xw::set_property_from_patch(faceNormal, patch, buffers);
        xw::set_property_from_patch(faceVertices, patch, buffers);
        xw::set_property_from_patch(faceIndex, patch, buffers);
        xw::set_property_from_patch(modifiers, patch, buffers);
        xw::set_property_from_patch(object, patch, buffers);
        xw::set_property_from_patch(picked, patch, buffers);
        xw::set_property_from_patch(uv, patch, buffers);
        xw::set_property_from_patch(indices, patch, buffers);
    }

    template <class D>
    inline xpicker<D>::xpicker()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpicker<D>::set_defaults()
    {
        this->_model_name() = "PickerModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xpicker>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xpicker>;
        extern template xw::xmaterialize<xthree::xpicker>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xpicker>>;
        extern template class xw::xgenerator<xthree::xpicker>;
        extern template xw::xgenerator<xthree::xpicker>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xpicker>>;
    #endif
#endif

#endif